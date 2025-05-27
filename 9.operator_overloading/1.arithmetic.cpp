/*
1.arithmetic
산술연산자 오버로딩
왠만하면 오버로딩하지말고 함수 사용하자
*/

#include <iostream>

using namespace std;

class Cents {
   private:
    int m_cents;

   public:
    Cents(int cents = 0) : m_cents(cents) {}
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2) {
    return Cents(c1.getCents() + c2.getCents());
}
Cents operator+(const Cents& c1, const Cents& c2) {
    return Cents(c1.getCents() + c2.getCents());
}

int main() {
    Cents c1 = Cents(5);
    Cents c2 = Cents(10);
    Cents c3 = add(c1, c2);  // add 함수를 통해 Cents 객체를 더함
    cout << "Cents: " << c3.getCents() << endl;  // 15
    c3 = c1 + c2 + c3;  // operator+를 통해 Cents 객체를 더함
    cout << "Cents: " << c3.getCents() << endl;  // 30
    c3 = c1 + 100;  // operator+를 통해 Cents 객체와 정수를 더함
    // 암묵적 형변환 c1 + Cents(100)와 동일
    cout << "Cents: " << c3.getCents() << endl;  // 105
}