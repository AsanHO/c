/*
3.derived_class.cpp
//유도된 클래스들의 생성 순서
*/
#include <iostream>
using namespace std;
class Mother {
   public:
    int m_i;
    Mother() : m_i(1) { cout << "Mother Construct" << endl; }
};
class Child : public Mother {
   public:
    double m_d;

   public:
    // Child() :Mother(), m_d(1.0) { cout << "Child Construct" << endl; }
    //  위 코드 처럼 실제로는 부모클래스 생성자가 숨겨져 있다.
    Child() : m_d(1.0) { cout << "Child Construct" << endl; }
};

int main() {
    Child c1;
    /*
    Mother Construct
    Child Construct
    */
    /*
    디스트럭터의 경우
    Mother Construct
    Child Construct
    */
}