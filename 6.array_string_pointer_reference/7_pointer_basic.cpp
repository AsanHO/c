#include <iostream>

using namespace std;

void check_ptr(double *ptr) {
    cout << "adress: " << &ptr << endl;
    if (ptr == nullptr) {
        cout << "ptr_1 is null" << endl;
    } else {
        cout << "ptr_1 is not null" << endl;
        cout << "value of ptr: " << *ptr << endl;
    }
}
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
    // 그렇다면 포인터 선언시 왜 데이터타입을 지정하는가?
    // 1. dereference 시 어떤 타입으로 값을 가져올지 알아야하기 때문에
    // 2. 포인터 연산시(ptr+1 과 같은) 1이 몇바이트인지 알기 위해서

    /*
    ***************************************
    널포인터
    포인터도 마찬가지로 쓰레기 주소의 값을 확인할 수 있다.(버그임)
    이런문제를 방지하기 위해 널포인터를 사용하며 실제로 많이 사용한다.
    */
    double *ptr_1 = 0;
    double *ptr_2 = nullptr;  // 포인터를 초기화할 때는 nullptr을 사용한다.

    // nullptr은 C++11부터 사용 가능하다.
    // 0은 C++98부터 사용 가능하다.
    // 0은 C++11부터 deprecated 되었다.
    // 0은 C++11부터 nullptr로 대체되었다.

    check_ptr(ptr_1);
    check_ptr(ptr_2);
    double d = 1.23;
    ptr_2 = &d;
    check_ptr(ptr_2);

    cout << "adress : " << &ptr_2 << endl;
    // 포인터 또한 주소를 담는 변수이기에 함수 호출 과정에서의값(파라미터값이
    // 복사가 일어나므로)과 메인 안에서의 값이 다른 것을 확인할 수 있다.

    return 0;
}
