/*
6.virtual_tables.cpp
*/

#include <iostream>
using namespace std;

class Base {
   public:
    // FunctionPointer *_vptr;
    void func1() { cout << "Base::func1()" << endl; }
    void func2() { cout << "Base::func2()" << endl; }
};

class Derived : public Base {
   public:
    // FunctionPointer *_vptr;
    void func1() { cout << "Derived::func1()" << endl; }
    virtual void func3() { cout << "Derived::func3()" << endl; }
};

int main() {
    cout << sizeof(Base) << endl;     // Outputs the size of Base class
    cout << sizeof(Derived) << endl;  // Outputs the size of Derived class
    // virtual 키워드가 없다면
    // 1\n1이 출력됨
    // virtual 키워드가 있다면
    // 8\n8이 출력됨
    // 이는 Base 클래스에 가상 함수 테이블이 존재하기 때문
    // 가상 함수 테이블은 클래스의 가상 함수에 대한 포인터를 저장
    // 가상 함수가 없으면 가상 함수 테이블이 필요하지 않음
    return 0;
}