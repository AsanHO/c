// 6-13.pointer_with_const.cpp

#include <iostream>

using namespace std;
int main() {
    // case1 : 상수포인터는 역참조를 통해 값을 바꿀 수 없다.
    const int value = 5;
    const int *ptr = &value;
    //*ptr = 10; // Error: cannot assign to variable 'ptr' with const-qualified
    // type 'const int *'
    cout << *ptr << endl;  // 5

    // case2 : 상수포인터에 선언된 주소의 변수가 상수가 아닌경우 값을 바꿀수
    // 없지만, 역시 역참조를 통한 수정은 불가능하다.
    int value2 = 10;
    const int *ptr2 = &value2;
    value2 = 20;  // OK: value2 is not const
    // *ptr2 = 30; // Error: cannot assign to variable 'ptr2' with
    // const-qualified
    cout << *ptr2 << endl;  // 20

    // case3 : 상수포인터는 포인터의 주소의 값을 바꿀 수 없는 것이지 주소를
    // 바꿀수는 있다.
    int value3 = 3;
    const int *ptr3 = &value3;
    int value3_1 = 5;
    ptr3 = &value3_1;
    cout << *ptr3 << endl;  // 5

    // case4 : 밑의 코드의 경우 위 케이스들과 달리 값을 변경 가능하지만 주소값은
    // 변경이 불가능하다.
    int value4 = 5;
    int *const ptr4 = &value4;

    *ptr4 = 10;
    // ptr4 = &value3;  // Error: cannot assign to variable 'ptr4' with
    // const-qualified type 'int *const'
    cout << *ptr4 << endl;  // 10

    // case5 : 위의 코드와 달리 주소값과 역참조값 변경 모두 불가능하다.
    int value = 5;
    const int *const ptr = &value;
    // *ptr = 10; // Error: cannot assign to variable 'ptr' with
    // ptr = &value3;  // Error: cannot assign to variable 'ptr' with

    return 0;
}