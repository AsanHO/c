/*
constructors.cpp
*/

#include <iostream>

using namespace std;

class Fraction {
   private:
    int m_numerator;  // 멤버를 의미하기때문에
                      // m_ 접두사를 붙이는 것이 관례
    int m_denominator;

   public:
    // 생성자(Constructor)
    // 객체가 생성될 때 호출되는 함수
    // 객체의 초기화를 담당

    Fraction(const int& num, const int& den = 1) {
        if (den == 0) {
            std::cout << "Error: Denominator cannot be zero. Setting to 1."
                      << std::endl;
            m_denominator = 1;  // 분모가 0인 경우, 기본값으로 1 설정
        } else {
            m_denominator = den;
        }
        m_numerator = num;
    }

    void display() const {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }
};

class FractionErrorTest {
   private:
    int m_numerator;
    int m_denominator;

   public:
    // FractionErrorTest(){} 아무일도 안는 기본 생성자 함수가 숨어져 있다. ->
    // 쓰레기값 유도
    void display() const {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }
};

int main() {
    // Fraction 객체 생성
    Fraction f1(3, 4);  // 3/4
    Fraction f2{5, 0};  // 분모가 0인 경우

    FractionErrorTest f3;  // 기본 생성자 호출

    f1.display();  // 출력: 3/4
    f2.display();  // 출력: Error 메시지 후 5/1
    f3.display();  // 출력: 0/0 (기본값)

    return 0;
}