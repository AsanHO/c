/*
11.static_member_func.cpp
10에서 static 멤버 변수에 대해 알아보았다.
이번에는 static 멤버 함수에 대해 알아보자.
*/
#include <iostream>

using namespace std;

class Test {
   private:  // private선언 이후 바로 이전 10과 달리 코드 동작이 되지 않는다.
    static int s_id;  // static 멤버 변수 선언
    int m_id;

   public:
    static int getId() {  // static 멤버 함수
        // m_id = 100;  // static 멤버 함수 내에서 인스턴스 멤버 변수에 접근할
        // 수 없음 static 멤버 함수는 static 멤버 변수에만 접근할 수 있다.
        // !!!static에서는 this 포인터를 사용할 수 없다.!!! 때문에 Constructor
        // 에서도 this 포인터를 사용할 수 없다(다만 간접적으로 접근 가능)
        return s_id;  // 클래스의 static 멤버 변수에 접근
    }
    static void setId(const int& num) {  // static 멤버 함수
        s_id = num;
    }

    int temp() { return this->s_id; }
};

int Test::s_id = 10;  // static 멤버 변수 정의 및 초기화

int main() {
    cout << Test::getId() << endl;  // 10
    Test t1, t2;

    cout << t1.getId() << endl;  // 10
    t1.setId(20);                // static 멤버 함수를 통해 s_id를 20으로 설정
    cout << t2.getId() << endl;  // 10

    int (Test::*pFunc)() = &Test::temp;  // 인스턴스 멤버 함수 포인터
    cout << (t1.*pFunc)() << endl;       // 20
    int (*pFunc2)() = &Test::getId;      // 인스턴스 멤버 함수 포인터
    cout << pFunc2() << endl;            // 20
    // 위 코드를 통해 static 멤버 함수는 인스턴스의 의존성없이 호출할 수 있음을
}