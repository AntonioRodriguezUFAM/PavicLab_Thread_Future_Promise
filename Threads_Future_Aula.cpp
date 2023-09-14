#include <iostream>
#include <thread>
#include <future>
#include <string>


using namespace std;

int A(int a, int b) {
    return a + b;
}

int B(int c, int d) {
    return c + d;
}

int C(int A, int B) {
    return A + B;
}

int main()
{
    int ant;
    std::future<int> fA = std::async(std::launch::async, A, 2, 2);
    std::future<int> fB = std::async(std::launch::async, B, 10, 10);
    int freturnA = fA.get();
    int freturnB = fB.get();

    std::future<int> fC = std::async(std::launch::async, C, freturnA, freturnB);
    int freturnC = fC.get();
    std::cout << std::to_string(freturnC) << std::endl;
    return 0;
}