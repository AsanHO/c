/* 18.void_pointer.cpp
포인터는 주소고 주소는 집의 크기에 상관이 없는데
굳이 자료형을 지정해줘야 하는가?에 대한 의문을 해결한다.
*/
#include <iostream>

using namespace std;

int main() {
    int i = 5;
    float f = 3.14;
    char c = 'A';

    void *ptr = nullptr;

    ptr = &i;
    ptr = &f;
    // ptr = &c;

    // cout << ptr +1 << endl;  // void 포인터는 값 단위를 알 수 없기때문에
    // 연산이 불가능하다. cout << *ptr << endl;  // void 포인터는 역참조를 할 수
    // 없다.
    cout << *(static_cast<float *>(ptr))
         << endl;  // void 포인터는 역참조를 할 수 없다.
    // static_cast를 통해 void 포인터를 int 포인터로 변환 후 역참조

    // 자주쓰지는 않지만 써야할때가 있다. 후술예정
    return 0;
}