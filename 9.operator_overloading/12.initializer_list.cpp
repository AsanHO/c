/*
12.initializer_list.cpp
*/
#include <initializer_list>
#include <iostream>

using namespace std;

class IntArray {
   private:
    unsigned m_length = 0;
    int *m_data = nullptr;

   public:
    IntArray(unsigned length) : m_length(length) {
        m_data = new int[m_length];  // 동적 메모리 할당
    }
    ~IntArray() {
        delete[] m_data;  // 동적 메모리 해제
    }

    IntArray(const initializer_list<int> &list) : m_length(list.size()) {
        m_data = new int[m_length];  // 동적 메모리 할당
        unsigned i = 0;
        for (const auto &item : list) {
            m_data[i] = item;  // 초기화 리스트의 값으로 배열 초기화
            i++;
        }  // foreach 로만 구현 가능
        // 꿀팁 : 라이브러리를 구현하려고 하기 보다 분석(어떻게
        // 구현되어있는지)을 하는 것이 좋다.
    }
    // TODO : overloading assignment operator
    friend ostream &operator<<(ostream &out, const IntArray &arr) {
        for (unsigned i = 0; i < arr.m_length; ++i) {
            out << arr.m_data[i] << " ";
        }
        out << endl;
        return out;
    }
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};           // 배열 초기화
    int *arr2 = new int[5]{1, 2, 3, 4, 5};  // 동적 배열 초기화

    auto li = {10, 20, 30};

    IntArray intArray1(5);              // 일반 생성자 호출
    IntArray intArray2 = {10, 20, 30};  // 초기화 리스트 생성자 호출
    cout << intArray1;                  // 출력: 0 0 0 0 0
    cout << intArray2;                  // 출력: 10 20 30
}