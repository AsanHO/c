/*
4.derived_class_init.cpp
*/

#include <iostream>
using namespace std;
class Mother {
   public:
    int m_i;
    Mother(const int& input = 0) : m_i(input) { cout << "Mother Construct" << endl; }
};
class Child : public Mother {
   public:
    float m_d;

   public:
    Child() : m_d(1.0), Mother(1024) { cout << "Child Construct" << endl; }
};

int main() {
    Child c1;
    cout << sizeof(Mother) << endl;
    cout << sizeof(Child) << endl;
    cout << sizeof(c1) << endl;
    // 자식변수의 사이즈는 자기자신과 부모클래스를 포함한다.
}