/*
13.anonymous.cpp
객체를 사용할때 이름이 붙은 변수를 선언하지 않고 바로 사용하는 익명객체에 대해 알아보자
*/

#include <iostream>
using namespace std;

class Test {
   public:
    Test() { cout << "Test 생성자 호출" << endl; }   // 생성자
    ~Test() { cout << "Test 소멸자 호출" << endl; }  // 소멸자
    void display() const { cout << "hi" << endl; }   // 멤버 함수
};
int main() {
    // rvalue처럼 작동한다.
    Test().display();  // Test 클래스의 객체를 생성하고 display() 호출
    Test().display();  // Test 클래스의 객체를 생성하고 display() 호출
    // Test 객체를 생성하고 display() 함수를 호출하는 익명 객체 사용

    return 0;
}
