// 6-16.ptr&ref's_member_selection.cpp

#include <iostream>

using namespace std;

struct Person {
    int age;
    double weight;
};
int main() {
    Person person;

    person.age = 25;
    person.weight = 70.5;

    Person &ref = person;
    ref.age = 30;
    ref.weight = 60;
    Person *ptr = &person;

    ptr->age = 35;
    (*ptr).age = 40;  // 우선순위로 인한 코드스타일

    Person &ref2 = *ptr;
    ref2.age = 45;
    return 0;
}