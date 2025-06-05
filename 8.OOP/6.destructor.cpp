/*
6.destructor
생성자의 반대가 되는 소멸자
- 소멸자는 클래스 이름 앞에 ~를 붙여서 정의
- 소멸자는 객체가 소멸될 때 자동으로 호출되는 함수
- 생성자와 달리 매개변수를 가질 수 없음
- 소멸자는 인스턴스가 메모리에서 해제될 때 내부에서 자동으로 호출되며,
(⚠️중요!!!!)동적할당의 경우 영역을 벗어나도 자동으로 메모리가 해제되지 않기
때문에 delete로 메모리를 해제할 때만 소멸자가 호출된다.
- 소멸자를 프로그래머가 직접 호출하는 것은 대부분의 경우 권장되지 않는다.
*/
#include <iostream>

using namespace std;
class SimpleClass {
   private:
    int m_id;

   public:
    SimpleClass(const int& id) : m_id(id) {}

    // 소멸자 정의
    // 클래스 이름 앞에 ~(틸다)를 붙여서 정의
    // 소멸자는 매개변수, 반환값이 없으며, void를 사용하지 않음
    ~SimpleClass() { cout << m_id << " : Destructor called!" << endl; }

    void display() const { cout << "ID: " << m_id << endl; }
};

class IntArray {
   private:
    int* m_arr =
        nullptr;  // 사실 벡터를 쓰면 밑의 절차를 할 필요는 없음. 심지어 대부분
                  // 성능도 좋음. 물론 커스텀하면 벡터보다 좋을 수도 있음
    int m_length = 0;

   public:
    IntArray(const int& length) {
        m_length = length;
        m_arr = new int[m_length];
        cout << "constructor called, length: " << m_length << endl;
    }
    ~IntArray() {
        delete[] m_arr;  // 동적 할당된 메모리는 소멸되어도 delete 안하면 메모리
                         // 누수 발생
        cout << "Destructor called, length: " << m_length << endl;
    }
};
int main() {
    SimpleClass obj(1);                       // 생성자 호출
    SimpleClass* obj2 = new SimpleClass{12};  // 생성자 호출

    delete obj2;  // 출력: ID: 1

    while (true) {
        IntArray arr(1000000000);  // 동적 할당된 객체 생성
    }
    // 소멸자는 main 함수가 끝나면서 자동으로 호출되거나 위처럼 delete를 통해
    // 호출됨

    return 0;  // 프로그램 종료 시 소멸자 호출
}