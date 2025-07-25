/*
7.pointer_specialization.cpp
*/

#include <iostream>
using namespace std;

template <class T>
class A {
   private:
    T m_value;

   public:
    A(const T& value) : m_value(value) {}
    void print() { cout << "Value: " << m_value << endl; }
};

template <class T>
class A<T*> {
   private:
    T* m_value;

   public:
    A(T* value) : m_value(value) {}
    void print() { cout << "Pointer Value: " << *m_value << endl; }
};

int main() {
    A<int> a_int(123);
    a_int.print();

    int temp = 456;

    A<int*> a_int_ptr(&temp);
    a_int_ptr.print();  // Prints the address of temp

    double temp_double = 3.14;
    A<double*> a_double_ptr(&temp_double);
    a_double_ptr.print();  // Prints the address of temp_double

    return 0;
}