// 6-15.refvalue_with_const.cpp
// 포인터 상수의 경우의 수 3가지(주소,값,주소+값)
// 참조변수는 더 쉽게 사용가능하다.
#include <iostream>

using namespace std;

int test(const int &ref) {
    // 참조변수를 전달했으므로 값 복사가 일어나지 않는다.
    // 값을 바꿀 수 없다.
    cout << ref << endl;
    cout << ref << endl;
    return ref;
}
int main() {
    int x = 5;
    // int &ref_x = 10; 참조변수에 리터럴을 넣는 것은 불가능
    const int &ref_x = 10;  // 상수 참조변수는 가능
    cout << test(3 + 4) << endl;
    return 0;
}