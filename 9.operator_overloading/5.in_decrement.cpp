/*
5.in_decrement.cpp
*/
#include <iostream>

using namespace std;

class Digit {
   private:
    int m_digit;

   public:
    Digit(int digit = 0) : m_digit(digit) {}

    // prefix
    Digit& operator++() {
        ++m_digit;
        return *this;
    }
    // postfix
    Digit operator++(int) {  // postfix는 int 매개변수를 사용하여 구분
        Digit temp = *this;  // 현재 상태를 저장
        ++m_digit;           // 증가
        return temp;         // 이전 상태 반환
    }
    friend std::ostream& operator<<(std::ostream& out, const Digit& c) {
        out << c.m_digit;
        return out;
    }
};

int main() {
    Digit d(5);

    cout << ++d << endl;
    cout << d++ << endl;
    cout << d << endl;
    return 0;
}