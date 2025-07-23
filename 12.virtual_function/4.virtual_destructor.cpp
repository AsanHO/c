/*
4.virtual_destructor.cpp
*/
#include <iostream>
using namespace std;

class Base {
   public:
    virtual ~Base() { cout << "~Base()" << endl; }
    // virtual이 없으면 Base의 소멸자만 호출되고 Derived의 소멸자는 호출되지
    // 않음 부모의 형태를 한 자식객체의 소멸자도 호출되도록 하기 위해서는
    // virtual 소멸자를 사용해야 함
};

class Derived : public Base {
   private:
    int *m_array;

   public:
    Derived(int size) {
        m_array = new int[size];
        cout << "Derived()" << endl;
    }
    virtual ~Derived() {  // virtual은 cascade가 적용되어 부모에 선언되면 자식에
                          // 선언할 필요가 없으나 관행 상 자식에 선언하는 것이
                          // 좋음
        cout << "~Derived()" << endl;
        delete[] m_array;
    }
};

int main() {
    // Derived derived(5);

    Derived *derived2 = new Derived(10);
    Base *base = derived2;
    delete base;  // Calls Derived's destructor, then Base's destructor
    return 0;
}