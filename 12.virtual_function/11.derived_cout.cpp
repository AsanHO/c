/*
11.derived_cout.cpp
유도클래스에서 출력 연산자 사용하기
*/
#include <iostream>
using namespace std;
class Base {
   public:
    Base() {}
    friend ostream& operator<<(ostream& out, const Base& b) { return b.print(out); }
    // friend는 멤버가 아니기 때문에 오버라이딩을 할수없다.
    virtual ostream& print(ostream& out) const {
        out << "Base class";
        return out;
    }
};
class Derived : public Base {
   public:
    Derived() {}
    virtual ostream& print(ostream& out) const override {
        out << "Derived class";
        return out;
    }
};

int main() {
    Base b;
    Derived d;

    cout << b << endl;  // Base class
    cout << d << endl;  // Derived class

    Base& baseRef = d;
    cout << baseRef << endl;  // Derived class, virtual function dispatch occurs

    return 0;
}
