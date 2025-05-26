/*
9.const_instance.cpp
여담이지만 const는 가능하다면 많이 사용하는 편이 좋다. 클래스든 일반 변수든
const를 사용하면 코드의 안정성을 높이고, 의도치 않은 변경을 방지할 수 있다.
*/

#include <iostream>

using namespace std;

class SomeClass {
   public:
    int m_value = 0;

    SomeClass(const SomeClass& st_in) {  // 복사 생성자 (직접 작성하지 않아도
                                         // 컴파일러가 자동으로 생성해줌)
        // 복사 생성자는 객체가 복사될 때 호출되는 특별한 생성자
        setValue(st_in.m_value);
        cout << "copy constructor called" << endl;
    }
    SomeClass() { cout << "constructor called" << endl; }
    void setValue(int value) { m_value = value; }
    int getValueV1() { return m_value; }
    int getValueV2() const {
        return m_value;
    }  // const 멤버 함수 :
       // 이 멤버함수는 객체의 상태를 변경하지 않음을 컴파일러에게 전달함
};

void print(SomeClass st) {
    cout << &st << endl;
    cout << st.getValueV2() << endl;
}

void printV2(const SomeClass& st) {
    cout << &st << endl;
    cout << st.getValueV2() << endl;
}

class constTestClass {
   public:
    string m_vlaue = "default";
    const string& getValue() const {  // const 타입으로 오버로딩이 가능하다.
        cout << "const version called" << endl;
        return m_vlaue;
    }
    string& getValue() {
        cout << "non-const version called" << endl;
        return m_vlaue;
    }
};

int main() {
    const SomeClass something;
    // something.setValue(10);  // 오류: const 객체는 멤버 함수를 수정할 수
    // 없음 cout << something.getValue() << endl;  // 오류: const 객체는
    // 멤버 함수를 수정할 수 없음
    cout << something.getValueV2() << endl;  // OK: const 멤버 함수 호출 가능

    SomeClass another;
    cout << another.getValueV2() << endl;  // OK: const 멤버 함수 호출 가능
    cout << &another << endl;              // 일반 객체의 주소 출력
    print(another);
    // 주소가 다른데 왜 생성자 함수는 한 번만 호출되는가?
    // 왜냐하면 복사용 생성자 함수가 호출된다.
    printV2(another);  // const 참조로 전달, 복사 생성자 호출 안 됨 : 최적화완료

    const constTestClass test1;
    cout << test1.getValue() << endl;  // const 버전 호출
    constTestClass test2;
    cout << test2.getValue() << endl;  // non-const 버전 호출
}