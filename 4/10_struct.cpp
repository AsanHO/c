/*
하나의 자료형으로 객체를 설명하는 것은 쉽지 않다.
다양한 요소를 묶어 하나의 자료형을 사용하는 것이 구조체다.
클래스를 이해하기 위한 길목이다.
*/
#include <iostream>
#include <string>

using namespace std;

// void print_human(double height, float weight, int age, string name) {}

// 위처럼 쓰면 피로해진다.
// 밑에처럼 구조체를 쓰자
struct Person {
    double height;  // 멤버
    float weight;
    int age;
    string name;
    int default_num = 123;  // 디폴트값
    void print() {
        cout << height << endl;
        cout << weight << endl;
        cout << age << endl;
        cout << default_num << endl;
        cout << name << endl;
    }
};
void print_human(Person person) {
    cout << person.height << endl;  // . : 멤버 셀텍트 오퍼레이트 연산자
    cout << person.weight << endl;
    cout << person.age << endl;
    cout << person.name << endl;
}
int main() {
    // double height1, height2, height3;
    // float weight;
    // int age;
    // string name;

    Person me{2.0, 100, 20, "uno"};
    print_human(me);
    me.print();

    Person me2;
    me2 = me;
    me2.print();
    // 클래스와 구조체의 복사는 까다로운 편이다.
    return 0;
}