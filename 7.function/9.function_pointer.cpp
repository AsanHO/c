/*
9.function_pointer.cpp
객체지향으로 이어지는 중요한 개념
함수포인터는 복잡하고 어려운 형태를 간단하게 구현할 수 있게 해준다.
*/

#include <array>
#include <functional>  // 사용하진 않았으나 유용하게 사용할 여지가 있다.
#include <iostream>

using namespace std;

int func() { return 5; }
int func2() { return 10; }

bool checkEven(const int& i) { return i % 2 == 0; }
bool checkOdd(const int& i) { return i % 2 != 0; }

typedef bool (*CheckFunc)(const int&);

void printNumber(const array<int, 10>& arr, CheckFunc check_fnc = checkEven) {
    for (auto i : arr) {
        if (check_fnc(i) == true) cout << i << " ";
    }
    cout << endl;
}
int main() {
    cout << reinterpret_cast<void*>(func) << endl;
    int (*fcnptr)() = func;    // 물론 매개변수 타입도 같아야한다.
    cout << fcnptr() << endl;  // 5
    fcnptr = func2;
    cout << fcnptr() << endl;  // 10

    array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printNumber(arr, checkEven);
    printNumber(arr, checkOdd);

    return 0;
}