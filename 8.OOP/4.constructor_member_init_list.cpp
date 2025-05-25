/*
4.constructor_member_init_list
*/
#include <iostream>
class SomeClass {
   private:
    int m_int = 111;  // 멤버변수 초기화를 지정해도 생성자가 우선임
    double m_double;
    char m_char;

   public:
    // 생성자
    SomeClass(int i = 0, double d = 0.0, char c = 'a')
        : m_int(i), m_double(d), m_char(c) {
        // 멤버 초기화 리스트를 사용하여 멤버 변수 초기화
        // 생성자 본문에서 초기화하지 않음
    }
    void print() const {
        std::cout << "m_int: " << m_int << ", m_double: " << m_double
                  << ", m_char: " << m_char << std::endl;
    }
};

int main() {
    SomeClass obj1;  // 기본 생성자 호출
    obj1.print();    // 출력: m_int: 0, m_double: 0, m_char: a
}