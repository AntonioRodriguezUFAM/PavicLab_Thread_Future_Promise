#include <iostream>
#include<thread>
#include <future>

using namespace std;

int Mult_thread( int x) {
	return x * 2;
}


int main() {

	future<int> resultFuture = std::async(std::launch::async, Mult_thread, 50);

	int result = resultFuture.get();

	cout << "Result from thread : " << result << endl;



	return 0;
}