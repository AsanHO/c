/*
5.function_try.cpp
*/
#include <iostream>
using namespace std;
class A {
   private:
    int m_x;

   public:
    A(int x) : m_x(x) {
        if (x <= 0) throw 1;
    }
};

class B : public A {
   public:
    // B(int x) : A(x) {}

    B(int x) try : A(x) {
    } catch (...) {
        cout << "Catch in B constructor" << endl;
        throw;  // rethrow
    }
};
void func() {
    try {
        throw -1;
    } catch (...) {
        cout << "Catch in func()" << endl;
    }
}
int main() {
    try {
        B b(0);
    } catch (...) {
        cout << "Catch in main()" << endl;
    }
    return 0;
}