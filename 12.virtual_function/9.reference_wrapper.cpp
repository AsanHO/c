/*
9.reference_wrapper
상속 구조에서는 아무래도 자식 클래스가 부모클래스 보다 많은 정보를 가지고 있는 경우가 많다.
그런데 부모클래스에 자식객체를 강제로 대입할경우
자식클래스의 정보가 손실될 수 있다. 이를 object slicing이라고 한다.
이 문제를 해결하기 위해 C++에서는 reference_wrapper를 제공한다.
*/
#include <functional>  // std::reference_wrapper
#include <iostream>
using namespace std;

class Base {
   public:
    int m_i = 0;
    virtual void print() const { cout << "I'm Base" << m_i << endl; }
};

class Derived : public Base {
   public:
    int m_j = 0;
    void print() const override { cout << "I'm Derived" << m_i << ", " << m_j << endl; }
};

void func(Base& b) { b.print(); }

int main() {
    Derived d;
    Base& b = d;
    b.print();

    Base c = d;  // Object slicing 발생
    c.print();

    // 주니어들이 자주 하는 실수 예제
    // std::vector<Base> my_vec;
    std::vector<std::reference_wrapper<Base>> my_vec;

    Derived x;
    Base y;
    my_vec.push_back(x);  // std::vector<Base> my_vec;일 시 Object slicing 발생
    my_vec.push_back(y);

    for (auto& i : my_vec) {
        i.get().print();  // Object slicing으로 인해 Derived의 정보가 손실됨
    }
    return 0;
}
