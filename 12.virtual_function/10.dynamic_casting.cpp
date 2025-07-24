/*
10.dynamic_casting.cpp
다형성을 활용하다보면 자식클래스가 부모 클래스의 포인터로 사용되는 경우가 많다.
이때, 이때 자식클래스의 포인터로 형변환이 필요한 경우가 있다.
이러한 형변환을 안전하게 수행하기 위해 dynamic_cast를 사용한다.
*/

#include <iostream>
#include <string>
using namespace std;

class Base {
   public:
    int m_i = 0;
    virtual void print() const { cout << "I'm Base" << m_i << endl; }
};
class Derived : public Base {
   public:
    int m_j = 1024;
    virtual void print() const override { cout << "I'm Derived" << m_i << ", " << m_j << endl; }
};
class Derived2 : public Base {
   public:
    string m_name = "DR2";

    virtual void print() const override { cout << "I'm Derived2" << m_i << ", " << m_name << endl; }
};

int main() {
    Derived d1;
    Base *base = &d1;
    // cout << base->m_j << endl;                       // 컴파일 에러: Base 클래스에는 m_j가 없기 때문에 접근할 수 없음
    auto *base_to_d1 = dynamic_cast<Derived *>(base);  // Base 포인터를 Derived 포인터로 안전하게 변환
    cout << base_to_d1->m_j << endl;
    d1.print();                                         // 멤버 변수는 오버라이딩 되지 않지만
                                                        // print() 함수는 Derived 클래스의 구현이 호출됨
    auto *base_to_d2 = dynamic_cast<Derived2 *>(base);  // 캐스팅에 실패하면 nullptr 반환
    // cout << base_to_d2->m_name << endl; 따라서 오류
    // static_cast도 있지만 dynamic_cast는 런타임에 타입 체크를 수행하여 안전성을 보장한다.
    // 즉 static_cast는 왠만하면 캐스팅을 해주는 편이다. 물론 오류는 체크 하지 않는다.

    return 0;
}
