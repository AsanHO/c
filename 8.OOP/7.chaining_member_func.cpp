/*
7.chaining_member_func
*/
#include <iostream>
using namespace std;
class Simple {
   private:
    int m_id;

   public:
    Simple(const int& id) {
        // this->setId(id); 사실 다른 언어들과 달리 this는 생략되어있다고 봐도 무방하다.
        setId(id);
    }

    void setId(const int& id) {
        // this->m_id = id;
        m_id = id;
        cout << this << ":" << m_id << endl;
    }
    void display() const { cout << "ID: " << m_id << endl; }

    Simple& add(const int& id) {
        m_id += id;

        return *this;  // this를 반환하여 메서드 체이닝 가능
    }
    Simple& sub(const int& id) {
        m_id -= id;
        return *this;
    }
    Simple& mul(const int& id) {
        m_id *= id;
        return *this;
    }
};
int main() {
    Simple s1 = Simple(1);
    Simple s2 = Simple(2);
    s1.setId(2);
    s2.setId(4);
    s2.add(2).sub(1).mul(3).display();  // 메서드 체이닝
}