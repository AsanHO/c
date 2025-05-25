/*
5.delegating_constructor.cpp
*/

#include <iostream>
#include <string>

using namespace std;

class Student {
   private:
    int m_id;
    string m_name;

   public:
    // 위임 생성자
    Student(const int& id) : Student(id, "Unknown") {  // 다른 생성자를 호출
    }
    // 생성자
    Student(const int& id, const string& name) : m_id(id), m_name(name) {}

    void display() const {
        cout << "ID: " << m_id << ", Name: " << m_name << endl;
    }
};

int main() {
    Student s1(1);           // 위임 생성자 호출
    Student s2(2, "Alice");  // 일반 생성자 호출

    s1.display();  // 출력: ID: 1, Name: Unknown
    s2.display();  // 출력: ID: 2, Name: Alice

    return 0;
}