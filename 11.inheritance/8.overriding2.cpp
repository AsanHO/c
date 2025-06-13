/*
8.overriding2
이번에는 함수를 아예 못쓰게 막아버리는 방법을 알아보자
*/

#include <iostream>
using namespace std;
class Base {
   protected:
    int m_i;

   public:
    Base(int value) : m_i(value) {}
    void print() { cout << "hi guys" << endl; }
};

class Derived : public Base {
   protected:
    double m_d;

   public:
    Derived(int value) : Base(value) {};
    using Base::m_i;

   private:
    using Base::print;
};

int main() {
    Base base(5);

    Derived derived(7);
    derived.m_i = 12;  // public: using Base::m_i;을 작성해주었기에 가능한 문법
    // derived.print();   //private를 적용해서 불가능한 문법
}