/*
10.convertingConstructor_explict_delete
*/
#include <cassert>
#include <iostream>
using namespace std;

class Fraction {
   private:
    int m_numerator;
    int m_denominator;

   public:
    Fraction(char c) = delete;  // char 타입의 매개변수를 받는 생성자는 삭제
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
        assert(denominator != 0);  // 분모가 0이 아니어야 함
    }  // explicit 생성자를 사용하여 암시적 변환 밑의 func(7)같은 암시적변환을 막는다.

    // 복사 생성자
    Fraction(const Fraction& other) : m_numerator(other.m_numerator), m_denominator(other.m_denominator) { cout << "Copy constructor called" << endl; }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        out << f.m_numerator << "/" << f.m_denominator << endl;
        return out;
    }
};

void func(Fraction frac) { cout << frac << endl; }

int main() {
    Fraction frac(3, 5);

    func(7);            // int를 Fraction으로 변환하는 생성자 호출
    func(Fraction(7));  // Fraction 객체를 직접 전달

    // func('2');  // 오류: char 타입의 매개변수를 받는 생성자는 삭제되었으므로 컴파일 오류 발생
    return 0;
};
