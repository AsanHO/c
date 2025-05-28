/*
11.deepCopy_shallowCopy.cpp
사실 이 기능을 구현할일은 없다. 모던 라이브러리 쓰면됨
하지만 컴퓨터에는 이러한 문제가 있고
다른 언어를 사용할 때에도 이문제를 프로그래머에게 감춰놨다는 사실을 알아두자.
*/
#include <cassert>
#include <iostream>

using namespace std;

class MyString {
   public:  // 테스트를 위해 캡슐화를 깸
    char *m_data = nullptr;
    int m_length = 0;

   public:
    MyString(const char *source = "") {
        assert(source);  // 문자열이 비어 있는 경우 단언
        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];  // 동적 메모리 할당

        for (int i = 0; i < m_length; ++i) {
            m_data[i] = source[i];  // 문자열 복사
        }
        m_data[m_length - 1] = '\0';  // 문자열 끝에 널 문자 추가
    };

    // 복사 생성자 주석처리시 얕은 복사(shallow copy)가 발생함
    MyString(const MyString &source) {
        cout << "Copy constructor called" << endl;
        m_length = source.m_length;
        if (source.m_data != nullptr) {
            m_data = new char[m_length];  // 동적 메모리 할당
            for (int i = 0; i < m_length; ++i) {
                m_data[i] = source.m_data[i];  // 문자열 복사
            }
        } else {
            m_data = nullptr;  // nullptr 처리
        }
    }
    // 대입 연산자 오버로딩
    MyString &operator=(const MyString &source) {
        // shallow copy
        // this->m_data = source.m_data;  // 주소를 복사
        // this->m_length = source.m_length;  // 길이를 복사
        // 위의 코드는 얕은 복사(shallow copy)로, source가 소멸되면 m_data가 해제되어
        // hello.m_data가 유효하지 않게 된다. 따라서 깊은 복사(deep copy)를 구현해야 한다.
        cout << "Assignment operator called" << endl;
        if (this == &source) return *this;  // 자기 자신에 대한 대입 방지

        delete[] m_data;  // 기존 메모리 해제

        m_length = source.m_length;
        if (source.m_data != nullptr) {
            m_data = new char[m_length];  // 동적 메모리 할당
            for (int i = 0; i < m_length; ++i) {
                m_data[i] = source.m_data[i];  // 문자열 복사
            }
        } else {
            m_data = nullptr;  // nullptr 처리
        }
        return *this;
    }

    ~MyString() {
        delete[] m_data;  // 동적 메모리 해제
    }

    char *getString() const {
        return m_data;  // 문자열 반환
    }
    int getLength() const {
        return m_length;  // 문자열 길이 반환
    }
};

int main() {
    MyString hello("Hello");

    cout << (int *)hello.m_data << endl;
    cout << hello.getString() << endl;

    {
        MyString copy = hello;
        cout << (int *)copy.m_data << endl;
        cout << copy.getString() << endl;  // "Hello"
    }  // copy 객체가 범위를 벗어나면서 소멸자 호출 -> hello.m_data가 해제됨

    cout << (int *)hello.m_data << endl;  // 주소가 여전히 유효함
    cout << hello.getString() << endl;    // "Hello"

    MyString world("World");
    MyString str1 = hello;  // 복사 생성자 호출
    MyString str2;
    str2 = world;  // 대입 연산자 호출

    // deep copy가 구현하기가 까다롭거나 귀찮은편인데 차라리 복사가 안되도록 막아버리는 임시방편도 있다.
    // 사실 이 기능을 구현할일은 없다. 모던 라이브러리 쓰면됨 이런 문제가 있다는 사실만 알아두자.
}
