/*
2.virtual_function_polymorphism.cpp
편리하나 속도가 느리다.
그 이유는
가상함수 테이블을 사용하기 때문이다. 후술예정
*/

#include <iostream>

using namespace std;
class A {
   public:
    virtual void func() { cout << "A" << endl; }
};
class B : public A {
   public:
    void func() {
        cout << "B" << endl;
    }  // virtual 키워드가 없어도 cascade 되어
       // 오버라이드가 가능하다.
       // 그래도 view를 위해 virtual 키워드를 사용하는 것이 좋다.
       // 당연하지만 오버라이딩 하려면 함수의 시그니쳐(이름, 리턴타입, 매개변수)가
       // 부모 클래스와 동일해야 한다.
};
class C : public B {
   public:
    void func() { cout << "C" << endl; }
};
class D : public C {
   public:
    void func() { cout << "D" << endl; }
};
int main() {
    A test = B();
    test.func();  // 오버라이드가 되지 않음, A::func() 호출

    A a;
    B b;
    C c;
    D d;

    A &ref = b;
    ref.func();  // 오버라이드가 됨, B::func() 호출

    B &ref2 = c;
    ref2.func();  // 오버라이드가 됨, C::func()
    /*
    B클래스의 func() 이 virtual키워드가 없음에도
    C클래스에서 오버라이드가 가능하다.
    이는 B클래스의 func()가 A클래스에서 virtual로 선언되
    있기 때문이다.
    따라서 A클래스에서 virtual로 선언된 함수는
    파생 클래스에서 오버라이드가 가능하다.
    */
}