#include<iostream>
#include<thread>
#include<future>


using namespace std;

int factorial(int N) {

	int res = 1;
	for (int i = N; i > 1; i--) {
		res *= i;
	}
	cout << "Result is: " << res << endl;
	return res;
}


int main() {

	int x;
	// Used the future to pass value from child (Thread) thread to parent (Main) thread!!
	
	//std::future<int> fu_1 = std::async(factorial, 5);
	std::future<int> fu_1 = std::async(std::launch::async,factorial, 5); // Create a Thread
	//std::future<int> fu_2 = std::async(std::launch::deferred, factorial, 5); //NO Create a Thread
	//std::future<int> fu_2 = std::async(std::launch::async | std::launch::deferred, factorial, 5); //May o Maynot Create a Thread

	// Do something else

	std::this_thread::sleep_for(chrono::milliseconds(20));
	//
	// Future!!
	x = fu_1.get();

	cout << "Get from the Main : " << x << endl;

	return 0;
}



/////
//#include<iostream>
//#include<thread>
//#include<future>
//
//
//using namespace std;
//
//int factorial_1(std::future<int>& f) {
//	int res = 1;
//
//	int N = f.get();
//	for (int i = N; i > 1; i--) {
//		res *= i;
//	}
//	cout << "Result is: " << res << endl;
//	return res;
//}
//
//int main() {
//
//	int x;
//
//	// Used the future to pass value from parent (main) thread to child (Thread)  thread using Promise!!
//	std::promise <int> P;
//	std::future <int> fu_03 = P.get_future();
//
//	std::future<int> fu_4 = std::async(std::launch::async, factorial_1, std::ref(fu_03));
//
//
//	// Do something else
//	std::this_thread::sleep_for(chrono::milliseconds(20));
//	P.set_value(5);
//
//	x = fu_4.get();
//
//	cout << "Get from the Child : " << x << endl;
//
//	return 0;
//}
//
