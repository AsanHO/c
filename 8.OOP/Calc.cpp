#include "Calc.h"
using namespace std;

Simple::Simple(const int& id) {
    setId(id);  // 생성자에서 setId 호출
}

void Simple::setId(const int& id) {
    m_id = id;  // this->m_id = id; 사실 this는 생략되어있다고 봐도 무방하다.
    cout << this << ":" << m_id << endl;
}

Simple& Simple::add(const int& id) {
    m_id += id;

    return *this;  // this를 반환하여 메서드 체이닝 가능
}
Simple& Simple::sub(const int& id) {
    m_id -= id;

    return *this;  // this를 반환하여 메서드 체이닝 가능
}
Simple& Simple::mul(const int& id) {
    m_id *= id;

    return *this;  // this를 반환하여 메서드 체이닝 가능
}

void Simple::display() { cout << "ID: " << m_id << endl; }