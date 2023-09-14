#include<iostream> // Std::cout, Std::cin
#include<thread>
#include<mutex>

using namespace std;
std::mutex mtx;


// Hola !!
void printHola() {
	cout << "Hola desde o Thread!!" << endl;
}

void printchao() {
	cout << "Chao desde o Thread!!" << endl;
}

void task_01(int reps) {
	for (int i = 0; i <= reps; i++) {
		cout << endl;
		cout << " Thread Reps 01: " << i << endl;
	}

}

void task_02(int reps) {
	for (int i = 0; i <= reps; i++) {
		cout << endl;
		cout << " Thread Reps 02: " << i << endl;
	}

}

void task_03(int reps) {
	for (int i = 0; i <= reps; i++) {
		cout << endl;
		cout << "Thread Reps 03: " << i << endl;
	}

}

// With Mutex and Lock
void Lock_task_01( int reps) {
	for (int i = 0; i <= reps; i++ ) {
		cout << endl;
		std::unique_lock<std::mutex> cadeado(mtx);
		cout << " Thread Reps 01: " << i << endl;
		cadeado.unlock();
	}

}

void Lock_task_02(int reps) {
	for (int i = 0; i <= reps; i++) {
		cout << endl;
		std::unique_lock<std::mutex> cadeado(mtx);
		cout << " Thread Reps 02: " << i << endl;
		cadeado.unlock();
	}

}

void Lock_task_03(int reps) {
	for (int i = 0; i <= reps; i++) {
		cout << endl;
		std::unique_lock<std::mutex> cadeado(mtx);
		cout << "Thread Reps 03: " << i << endl;
		cadeado.unlock();
	}

}


//************************************************************
/*  Tarefa:
	Thread A >> A =a+b
	Thread B >> B= c+d
	Thread C >> C= A+B
	*/

int sumaA(int a, int b) {
	return (a + b);

}

int sumaB(int c, int d) {
	return (c + d);

}

int sumaC(int A, int B) {
	return (A + B);

}




int main() {
	
	cout << "Hola desde o 1 st Main!!" << endl;
	thread thread_01(printHola); // criar o thread!!
	thread thread_02(printchao); // criar o thread!!
	
	cout << "Hola desde o 2 nd Main!!" << endl;

	thread_01.join();
	thread_02.join(); // Main wait !!

	cout << " End of Process!!" << endl;
	//*************************************************
	
	// Def Reps
	int resp1 = 5;
	int resp2 = 3;
	int resp3 = 2;

	cout << " Thread without Mutex!!" << endl;

	//// Call new thread for task 1 to 3
	thread task01(task_01, resp1);
	thread task02(task_02, resp2);
	thread task03(task_03, resp3);

	// Join all threads
	task01.join();
	task02.join();
	task03.join();


	cout << " Thread with Mutex!!" << endl;
	// Mutex
	thread task011(Lock_task_01, resp1);
	thread task021(Lock_task_02, resp1);
	thread task031(Lock_task_03, resp1);

	// Join all threads
	task011.join();
	task021.join();
	task031.join();

	/*
	Tarefa:
	// Parallel
	Thread A >> A =a+b
	Thread B >> B= c+d
	
	// Secuencial
	Thread C >> C= A+B
	*/
	
	int a = 12, b = 2, c = 4, d = 9;
	thread A(sumaA, a, b);
	thread B(sumaB, b, c);
	//thread C(sumaC, A, B);



	A.join();
	B.join();
	//C.join();


	cout << endl;
	cout << " End of Task 1 to 3!!" << endl;
	return 0;
}

