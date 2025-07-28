/*
7.std::weak_ptr.cpp
쉐어드 포인터를 사용할때 발생할 수 있는 순환 의존성 문제(Circular dependency
issues)와 이를 해결하는 라이브러리를 알아본다.
*/

#include <iostream>
#include <memory>
#include <string>

class Person {
    std::string m_name;
    // std::shared_ptr<Person> m_partner;
    std::weak_ptr<Person> m_partner;

   public:
    Person(const std::string &name) : m_name(name) {
        std::cout << m_name << " created\n";
    }
    ~Person() { std::cout << m_name << " destroyed\n"; }
    // 쉐어드 포인터가 m_partner를 지울수 없다 ㅜ

    friend bool partnerUp(std::shared_ptr<Person> &p1,
                          std::shared_ptr<Person> &p2) {
        if (!p1 || !p2) {
            return false;
        }
        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

        return true;
    }
    const std::shared_ptr<Person> getPartner() const {
        return m_partner.lock();
    }  // 위크 포인터는 .lock()메소드를 통해 쉐어드 포인터로 바꿔서
       // 전달해야한다.
    const std::string &getName() const { return m_name; }
};

int main() {
    auto uno = std::make_shared<Person>("uno");
    auto nakeum = std::make_shared<Person>("nakeum");
    partnerUp(uno, nakeum);

    std::cout << uno->getPartner()->getName() << std::endl;

    return 0;
}
