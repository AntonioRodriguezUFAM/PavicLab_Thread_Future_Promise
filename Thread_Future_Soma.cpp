#include <iostream>
#include<thread>
#include <future>

using namespace std;

void threadA(int a, int b, std::promise<int>&& promise) {

	int result = a + b;
	promise.set_value(result);
}

void threadB(int c, int d, std::promise<int>&& promise) {

	int result = c + d;
	promise.set_value(result);
}


void threadC(std::future <int>&&futureA, std::future <int>&& futureB) {

	int result = futureA.get() + futureB.get();
	std::cout << "Thread C Result : " << result << endl;

}



int main() {

	int a = 10, b = 2, c = 3, d = 4;

	std::promise <int> promiseA;
	std::future<int> futureA = promiseA.get_future();

	std::promise <int> promiseB;
	std::future<int> futureB = promiseB.get_future();


	thread threadSomaA(threadA, a, b, std::move(promiseA));
	thread threadSomaB(threadB, c, d, std::move(promiseB));

	threadSomaA.join();
	threadSomaB.join();

	thread threadSomaC(threadC, std::move(futureA), std::move(futureB));

	threadSomaC.join();





	return 0;

}