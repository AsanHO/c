/*
8.type_cast.cpp
*/
#include <iostream>

using namespace std;

class Cents {
   private:
    int m_cents;

   public:
    Cents(int cents = 0) : m_cents(cents) {}
    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    operator int() const { return m_cents; }  // Cents 객체를 int로 변환하는 타입 캐스트 연산자
};

class Dollar {
   private:
    int m_dollars = 0;

   public:
    Dollar(const int& input) : m_dollars(input) {}
    operator Cents() {
        return Cents(m_dollars * 100);  // Dollar를 Cents로 변환 (1달러 = 100센트)
    }
};

void printInt(const int& value) { cout << value << endl; }

int main() {
    Cents cents(7);

    printInt(cents);

    Dollar dollar(5);
    Cents cents2 = dollar;  // Dollar를 Cents로 변환
    printInt(cents2);       // 500 (5달러 = 500센트)
}