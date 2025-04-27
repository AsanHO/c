// 6-14.reference_variable.cpp
// 포인터와 const 쓰는것은 시각적으로 좀 불편한데
// 특정상황에서 참조변수를 사용하면 좀 더 편리하다.
#include <iostream>

using namespace std;

void print_val(
    int &n) {  // 바꾸지 못하게 하고 싶을때는 const int &n를 사용할 것
    n = 20;
    cout << n << endl;
}

struct Test {
    int a;
    float b;
};

struct Other {
    Test tt;
};
int main() {
    int value = 5;
    int *ptr = nullptr;
    ptr = &value;
    int &ref = value;  // 참조변수 : 별명처럼 사용가능

    cout << ref << endl;  // 5
    ref = 10;             // 참조변수는 역참조를 통해 값을 바꿀 수 있다.
    cout << value << " " << ref << endl;  // 10

    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr << endl;
    cout << &ptr << endl;
    // ref는 value의 별명으로 value와 같은 주소를 가리킨다.
    // 포인터는 포인터주소가 따로 존재한다.

    int x = 5;
    int &ref2 = x;

    const int y = 10;
    // int &ref3 = y;  // Error: cannot bind non-const lvalue reference of type
    const int &ref3 = y;  // OK: const lvalue reference can bind to const lvalue
    // const int& ref3 = 20;  // OK: const lvalue reference can bind to rvalue
    cout << x << endl;
    print_val(ref2);
    cout << x
         << endl;  // 포인터를 사용하지않고 손쉽게 복사가 아닌 참조 사용한다.

    // 실전에서 자주쓰는 패턴
    Other ot;
    int &v1 = ot.tt.a;  // Test 구조체의 a를 참조변수로 사용
    ot.tt.b = 3.14;
    ot.tt.b = 3.141;
    ot.tt.b = 3.1459;
    v1 = 20;
    v1 = 21;
    v1 = 22;
    // v1패턴이 가독성과 성능을 모두 만족한다.
    return 0;
}