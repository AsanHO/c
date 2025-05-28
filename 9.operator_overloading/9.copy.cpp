/*
9.copy
*/
#include <cassert>
#include <iostream>
using namespace std;

class Fraction {
   private:
    int m_numerator;
    int m_denominator;

   public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
        assert(denominator != 0);  // 분모가 0이 아니어야 함
    }

    // 복사 생성자
    Fraction(const Fraction& other) : m_numerator(other.m_numerator), m_denominator(other.m_denominator) { cout << "Copy constructor called" << endl; }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        out << f.m_numerator << "/" << f.m_denominator << endl;
        return out;
    }
};

int main() {
    Fraction frac(3, 5);
    Fraction copy = frac;

    cout << frac << copy << endl;  // 3/5
};
