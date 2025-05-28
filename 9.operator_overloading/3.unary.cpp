/*
3.unary
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

    // Unary operator overloading
    Cents operator-() const {
        return Cents(-m_cents);  // 음수로 변환
    }

    bool operator!() const {
        return (m_cents == 0);  // 0이면 true, 아니면 false
    }

    friend std::ostream& operator<<(std::ostream& out, const Cents& c) {
        out << c.m_cents << " cents";
        return out;
    }
};

int main() {
    Cents c1(5);
    Cents c2(10);

    cout << c1 << endl;   // 5 cents
    cout << -c2 << endl;  // 10 cents
    cout << -Cents(10) << endl;

    cout << !c1 << endl;        // false (0이 아님)
    cout << !Cents(0) << endl;  // true (0이므로)
    cout << !Cents(1) << endl;  // false (0이 아님)

    return 0;
}