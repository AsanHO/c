/*
7.overriding.cpp
오버로딩이나 오버라이딩을 하지 않고 그냥 이름이 다른 함수를 만들면 되지 않나라는 생각을 할수 있고,
그 판단 또한 논리적인 오류는 없으나 다음 챕터에서 배울 다형성에 매우 유용한 기능이다.
*/
#include <iostream>
using namespace std;
class Base {
   protected:
    int m_i;

   public:
    Base(int value) : m_i(value) {}

    void print() { cout << "I'm base" << endl; };

    friend std::ostream &operator<<(std::ostream &out, const Base &b) {
        out << "base output" << endl;
        return out;
    }
};

class Derived : public Base {
   protected:
    double m_d;

   public:
    Derived(int value) : Base(value) {};
    void print() {
        Base::print();
        cout << "I'm Derived" << endl;
    }
    friend std::ostream &operator<<(std::ostream &out, const Derived &b) {
        out << static_cast<Base>(b);
        // Derived에 Base가 포함되어 있기 때문에 가능하다!
        out << "Derived output" << endl;
        return out;
    }
};

int main() {
    Base base(5);
    base.print();
    Derived derived(7);
    derived.print();

    cout << base;
    cout << derived;
}