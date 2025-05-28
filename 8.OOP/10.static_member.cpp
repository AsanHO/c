/*
10.static_member.cpp
*/
#include <iostream>
using namespace std;
int generateId() {
    static int s_id = 0;
    return ++s_id;
}

class Test {
   public:
    static int s_id;  // static 멤버 변수 선언
};
int Test::s_id = 0;  // static 멤버 변수 정의 및 초기화

int main() {
    cout << "First ID: " << generateId() << endl;   // 1
    cout << "Second ID: " << generateId() << endl;  // 2
    cout << "Third ID: " << generateId() << endl;   // 3

    Test::s_id = 5;  // Test 클래스의 static 멤버 변수에 접근하여 값 설정
    // 위 코드는 심지어 클래스 인스턴스가 없어도 접근가능함을 보여준다.
    // 즉 인스턴스들이 공유하는 멤버변수라 생각하면 되겠다.
    Test t1, t2;
    t1.s_id = 10;                                // t1의 s_id를 10으로 설정
    cout << &t1.s_id << " " << t1.s_id << endl;  // 10
    cout << &t2.s_id << " " << t2.s_id << endl;  // 10
}