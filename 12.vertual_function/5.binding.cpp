/*
5.binding.cpp
가상 함수를 이용하는 다양성이 내부적으로 어떻게 작동하는지를 이해하려면
동적 바인딩과 정적 바인딩의 차이를 이해해야 한다.
*/

#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int main() {
    int x, y;
    cin >> x >> y;
    int op;
    cout << "0 : add, 1: subtract, 2: multiply" << endl;
    cin >> op;

    // static binding(early binding)
    // 모든 변수명과 함수 이름이 빌드 타임에 결정됨
    // 컴파일러는 함수 이름을 보고 어떤 함수를 호출할지 결정함
    // 속도는 빠르지만, 유연성이 떨어짐
    int result;
    switch (op) {
        case 0:
            result = add(x, y);
            break;
        case 1:
            result = subtract(x, y);
            break;
        case 2:
            result = multiply(x, y);
            break;
    }
    cout << result << endl;

    // dynamic binding(late binding)
    int (*func_ptr)(int, int) = nullptr;
    switch (op) {
        case 0:
            func_ptr = add;
            break;
        case 1:
            func_ptr = subtract;
            break;
        case 2:
            func_ptr = multiply;
            break;
    }
    cout << func_ptr(x, y) << endl;
    // 함수 포인터를 사용하여 동적 바인딩을 구현함
    // 함수 포인터는 런타임에 어떤 함수를 호출할지 결정함
    // 속도는 정적 바인딩보다 느리지만, 더 유연함
}