#include <iostream>

using namespace std;
int main() {
    // 메모리를 담는 변수 => 포인터
    int x = 10;

    cout << x << endl;

    // 위 코드가 실제로 실행되는 과정은 다음과 같다.
    // 1. 메모리 공간을 할당한다.
    // 2. 메모리 공간에 10을 저장한다.
    // 3. 메모리 공간의 주소를 x에 저장한다.
    // 4. x를 출력한다.
    // 5. 메모리 공간의 주소를 출력한다.
    // 6. 메모리 공간의 주소를 long int로 변환하여 출력한다.
    // 7. 메모리 공간의 주소를 역참조하여 출력한다.
    cout << &x << endl;  // & : adrress-of operator
    cout << (long int)&x << endl;
    cout << *&x << endl;  // * : dereference operator

    /*
    포인터를 쓰는 이유
    1. 메모리 공간을 직접 다룰 수 있다.
    2. 메모리 공간을 직접 다룰 수 있기 때문에, 메모리 공간을 효율적으로 사용할
    수 있다.
    3. 어레이를 다루기 위해 포인터를 사용한다. 모든 주소가 아닌 첫번째 주소와
    길이만 알면 된다.
    */

    double y = 3.14;
    cout << sizeof(x) << endl;                        // 4
    cout << sizeof(y) << endl;                        // 8
    cout << sizeof(&x) << " " << sizeof(&y) << endl;  // 8
    // 포인터의 크기는 해당 포인터가 가리키는 데이터의 크기와 상관없이 항상
     // int double struct 모두 8바이트이다. 32비트 시스템에서는 4바이트이다.\
    return 0;
}