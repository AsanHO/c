/*
14.assert.cpp
프로그래밍은 디버깅과의 싸움이다.
이때 컴파일러의 도움을 받을 때 사용하는 것이 이 단언하기이다.
throw 문을 사용하여 예외를 발생시키는 것과 비슷한 기능을 한다.
*/
#include <array>
#include <cassert>  // assert()를 사용하기 위한 헤더파일
#include <iostream>
using namespace std;

void printValue(const array<int, 5>& arr, int index) {
    assert(index >= 0 && index < arr.size() - 1);
    cout << "Value at index " << index << ": " << arr[index] << endl;
}

int main() {
    assert(true);
    // assert()는 조건이 false일 때 프로그램을 종료시키고, 오류 메시지를 출력한다.
    // assert()는 디버깅 모드에서만 작동하며, 릴리즈 모드에서는 작동하지 않는다.
    // assert()는 조건이 true일 때 아무런 동작도 하지 않는다.
    // assert()는 조건이 false일 때 프로그램을 종료시키고, 오류 메시지를 출력한다.

    array<int, 5> arr = {1, 2, 3, 4, 5};
    printValue(arr, 2);  // 정상적인 호출
    // printValue(arr, 5);  // assert()가 호출되어 프로그램이 종료됨

    const int x = 10;
    static_assert(x == 10, "x must be positive");  // 컴파일 타임에 조건을 검사
    return 0;
}