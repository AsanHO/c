#include <iostream>
/*
우리가 만든 프로그램에 메모리가 할당되는 것은 세가지 종류로 나뉜다.
1. 정적 메모리 할당 - static memory allocation(전역변수) / 스택
2. 자동 메모리 할당 - automatic memory allocation(지역변수) / 스택
3. 동적 메모리 할당 - dynamic memory allocation / 힙(스택보다 크고 느리다.)
포인터 관련하여 가장 까다로운 부분(danger)이지만 그만큼 숙달되면 좋은 엔지니어가
될 수 있다.
keyword : new, delete
*/
using namespace std;
int main() {
    int *ptr = new int;  // int형 포인터 ptr을 선언하고, 동적 메모리 할당
    // new int는 int형 메모리 공간을 할당하고, 그 주소를 ptr에 저장한다.
    // new는 os로부터 메모리를 가져와 할당한다.
    *ptr = 7;
    cout << *ptr << endl;  // 7
    cout << ptr << endl;   // 메모리 주소

    delete ptr;           // os에 메모리를 반납한다.
    cout << ptr << endl;  // 쓰레기값
    ptr = nullptr;        // ptr을 nullptr로 초기화한다.(권장)

    // cout << *ptr << endl;  // // 런타임 에러
    cout << ptr << endl;  // 메모리 주소

    int *ptr2 = new (nothrow) int;  // 메모리가 없을시에 오류를 반환하지 않고
                                    // nullptr을 반환한다.
    if (ptr2 == nullptr) {
        cout << "메모리 할당 실패" << endl;
    } else {
        cout << "메모리 할당 성공" << endl;
    }
    // memory leak
    // 메모리 누수
    while (true) {
        int *ptr3 = new int;
        cout << ptr3 << endl;
        // 실행시키면 메모리 누수가 발생한다.
    }

    return 0;
}