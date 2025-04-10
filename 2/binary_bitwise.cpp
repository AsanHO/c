#include <bits/stdc++.h>

/*
비트연산사용이유
최소단위 : 1바이트
1비트짜리도 최소단위를 사용해야하는 비효율적인 상황이 있다.
결론부터 말하면 메모리를 아끼기 위해 비트단위 연산을 사용한다.

비트연산은 unsigned가 일반적이다.

비트연산의 가장 많은 사례는 비트마스크(플래그)가 되겠다.
*/
int main() {
    using namespace std;

    unsigned int a = 5;

    cout << bitset<4>(a) << endl;

    unsigned int b = a << 2;

    // cout << bitset<4>(b) << " " << b << endl;

    cout << bitset<8>(a << 1) << " " << (a << 1) << endl;
    cout << bitset<8>(a << 2) << " " << (a << 2) << endl;
    cout << bitset<8>(a << 3) << " " << (a << 3) << endl;
    cout << bitset<8>(a << 4) << " " << (a << 4) << endl;
    // ✅ a << n 은 a*2^n 계산시 사용한다.

    a = 301;

    cout << bitset<16>(a >> 1) << " " << (a >> 1) << endl;
    cout << bitset<16>(a >> 2) << " " << (a >> 2) << endl;
    cout << bitset<16>(a >> 3) << " " << (a >> 3) << endl;
    cout << bitset<16>(a >> 4) << " " << (a >> 4) << endl;
    // ✅ a >> n 은 a/2^n 계산시 사용한다.

    /*
    비트플래그 : 배열을 좀더 컴팩트하게 사용할 수 있음 <- 속도도 더
    빠름(성능주의) 4바이트 기본단위에 bool 타입을 우겨넣는다.
    */
    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;

    cout << bitset<8>(opt0) << endl;
    cout << bitset<8>(opt1) << endl;
    cout << bitset<8>(opt2) << endl;
    cout << bitset<8>(opt3) << endl;

    unsigned char items_flag = 0;

    cout << bitset<8>(items_flag) << endl;
    return 0;
}