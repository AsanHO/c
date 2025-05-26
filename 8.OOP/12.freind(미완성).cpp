/*
12.freind.cpp
*/
#include <iostream>
using namespace std;

class B;  // B 클래스의 전방 선언

class A {
   private:
    int m_value = 1;
    friend void func(A& a, B& b);  // B 클래스의 private 멤버에 접근하기 위해 friend 선언
};

class B {
   private:
    int m_value = 2;
    friend void func(A& a, B& b);  // A 클래스의 private 멤버에 접근하기 위해 friend 선언
};
void func(A& a, B& b) {                             // private 지만 friend 함수이므로 접근 가능
    cout << a.m_value << " " << b.m_value << endl;  // A 클래스의 private 멤버에 접근
}

int main() {
    A a;
    B b;
    func(a, b);  // A 클래스의 private 멤버에 접근하는 함수 호출
    return 0;
}