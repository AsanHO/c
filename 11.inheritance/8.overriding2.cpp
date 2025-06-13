/*
8.overriding2
이번에는 유도된 클래스에서 상속받은 private변수 를 public으로 바꾸거나
public 함수를 private로 바꾸는 방법에 대해 알아보자. 이역시 오버라이딩이다.
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