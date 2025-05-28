/*
6.subscript
*/
#include <cassert>
#include <iostream>

using namespace std;

class IntList {
   private:
    int m_list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // 초기값 설정 :const 객체를 만들려면 필요

   public:
    void setItem(int index, int value) { m_list[index] = value; }
    int getItem(int index) const { return m_list[index]; }
    int* getList() { return m_list; }

    int& operator[](const int index) {
        assert(index >= 0 && index < 10);  // 인덱스 범위 검사 :: if 문보다 assert가 더 빠르다.
        return m_list[index];
    }
    const int& operator[](const int index) const {
        assert(index >= 0 && index < 10);
        return m_list[index];
    }
};

int main() {
    IntList my_list;
    my_list.setItem(3, 1);
    cout << my_list.getItem(3) << endl;  // 1
    my_list.getList()[3] = 10;
    cout << my_list.getList()[3] << endl;  // 10

    my_list[3] = 100;            // operator[] 사용, 레퍼런스를 반환하므로 값을 변경할 수도 있다.
    cout << my_list[3] << endl;  // 100

    const IntList const_list;  // const 객체 생성
    // const_list[3] = 200;  // 오류: const 객체는 값을 변경할 수 없다.
    cout << const_list[3] << endl;

    return 0;
}
