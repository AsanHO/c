/*
12.freind.cpp
객체지향의 기본 원칙은 캡슐화이다. 캡슐화는 객체의 내부 상태를 숨기고,
객체가 제공하는 메서드를 통해서만 상태를 변경할 수 있도록 하는 것이다.
하지만, 때로는 클래스의 private 멤버에 접근해야 할 필요가 있다.
캡슐화된 객체 모든 멤버가 private 이지만, friend 키워드는 이러한 레벨의 캡슐화를
무시하고 클래스의 private 멤버에 접근할 수 있게 해준다. 마치 몇몇 친구들만이
비밀을 알 수 있는 것과 같다.

- 연산자 오버로딩에서 자주쓰이는 표현
*/
#include <iostream>
using namespace std;

class B;  // B 클래스의 전방 선언

// friend function
class A {
   private:
    int m_value = 1;
    friend void func(
        A& a, B& b);  // B 클래스의 private 멤버에 접근하기 위해 friend 선언
};

class B {
   public:
   private:
    int m_value = 2;
    friend class C;  // C클래스는 제 public 멤버에 접근 할 수 있습니다!
    friend void func(A& a, B& b);
    void printB() {
        cout << "B's value: " << m_value
             << endl;  // B 클래스의 private 멤버에 접근
    }
};

class C {
   public:
    void printBfromC(B& b) {  // C 클래스의 private 멤버에 접근하는 함수
        cout << "B's value: " << b.m_value
             << endl;  // B 클래스의 private 멤버에 접근
    };
};

void func(A& a,
          B& b) {  // 전방선언관련 문제(단방향 접근이 아닌 양방향 접근)으로
                   // 인하여 클래스에는 프로토타입만 만들고 정의는 밖에서 작성
    cout << a.m_value << " " << b.m_value << endl;
}

int main() {
    A a;
    B b;
    func(a, b);  // A 클래스의 private 멤버에 접근하는 함수 호출
    C c;
    c.printBfromC(b);  // C 클래스의 private 멤버에 접근
    return 0;
}