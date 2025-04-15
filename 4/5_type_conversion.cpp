#include <bitset>
#include <iostream>
#include <typeinfo>
int main() {
    using namespace std;
    // 애매한 경우가 많다. 밑의 예처럼 사이즈가 큰 변수에서 사이즈가 작은 변수로
    // 이동이 되면, 버려지는 비트가 있다.
    // 물론 반대의 경우는 상관없지만 밑의 코드방식은 피해야한다.
    int i = 30000;
    char c = i;  // ITC
    cout << bitset<32>(i) << endl;
    cout << (int)c << endl;                                   // ETC
    cout << "char의 8비트인 00110000만 남은것이다." << endl;  // ETC

    double d = 0.123456789;
    float f = d;
    cout << (double)f << endl;

    // Implicit Type Conversion : 암시적 형변환 (coersion) : 컴파일러가 알아서
    // 수행 Explicit Type Conversion : 명시적 형변환 (casting) : 프로그래머가
    // 직접 변환
    // 암시적과 명시적은 동시에 발생 가능하며 깔끔한 코드를 지향한다면 암시적
    // 형변환이 일어나더라도 명시적 형변환을 해주는 것이 좋을 수도 있겠다.
    // 물론 반대의 경우는 상관없지만 밑의 코드방식은 피해야한다.
    int pi = (int)3.141592;  // 이렇게, (쓰지 않으면 컴파일러가 불평을 한다.)
    cout << pi << endl;
}