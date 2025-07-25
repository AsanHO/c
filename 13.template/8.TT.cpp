/*
8.TT.cpp
*/

#include <iostream>

using namespace std;

template <class T>
class A {
   private:
    T m_value;

   public:
    A(const T& value) : m_value(value) {}
    template <typename TT>
    void func(const TT& tt) {
        cout << typeid(T).name() << " : " << typeid(TT).name() << endl;
    }
    void print() { cout << "Value: " << m_value << endl; }
};

int main() {
    A<int> a_int(123);
    a_int.print();
    a_int.func<double>(3.14);
    a_int.func(128);
}