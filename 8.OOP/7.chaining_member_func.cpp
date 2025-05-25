/*
7.chaining_member_func
*/

#include "Calc.cpp"
int main() {
    Simple s1 = Simple(1);
    Simple s2 = Simple(2);
    s1.setId(2);
    s2.setId(4);
    s2.add(2).sub(1).mul(3).display();         // 메서드 체이닝
    Simple(0).add(2).sub(1).mul(3).display();  // 임시 객체 : 익명클래스
}