/*
1.inheritance.cpp
- 객체 지향에서 가장 중요하게 다루는 지점
- is-a relationship이라고도 부른다.
- 다양한 방법이 있어 밑의 코드도 100퍼센트 맞다고 할 수 없다.
*/
#include <iostream>

using namespace std;

class Mother {
   protected:  // 외부에서 접근이 불가능하지만 자식클래스에는 접근가능
    int m_i;

   public:
    void setValue(const int& i_in) { m_i = i_in; }
    int getValue() { return this->m_i; }
};

class Child : public Mother {  // derived class : 상속받은 클래스
   private:
    double m_d;

   public:
    void setValue(const int& i_in, const double& d_in) {
        m_d = d_in;
        Mother::setValue(i_in);  // m_i가 private여도 접근가능
    }
    void setValue(const double& d_in) { m_d = d_in; }
    double getValue() { return m_d; }
};
class Dautor : public Mother {};
class son : public Mother {};

int main() {
    Mother m1;
    m1.setValue(1024);
    cout << m1.getValue() << endl;

    Child child;
    child.setValue(1024, 128);
    cout << child.Mother::getValue() << endl;
    cout << child.getValue() << endl;
}