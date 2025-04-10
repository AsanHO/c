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
    const unsigned char item0 = 1 << 0;
    const unsigned char item1 = 1 << 1;
    const unsigned char item2 = 1 << 2;
    const unsigned char item3 = 1 << 3;

    cout << bitset<8>(item0) << endl;
    cout << bitset<8>(item1) << endl;
    cout << bitset<8>(item2) << endl;
    cout << bitset<8>(item3) << endl;

    unsigned char items_flag = 0;

    cout << bitset<8>(items_flag) << endl;
    // get item 0,3
    items_flag |= item0;
    items_flag |= item3;
    cout << bitset<8>(items_flag) << endl;
    // item 3 lost
    items_flag &= ~item3;  // !와 동일
    cout << bitset<8>(~item3) << endl;
    cout << bitset<8>(items_flag) << endl;

    // isHasItem
    // 내가 쓴 방식

    // cout << bitset<8>(items_flag) << endl;
    // // it has item1? 0
    // if ((items_flag | item1) == items_flag){
    //     cout << "isItem1 : 1" <<endl;
    // }else{
    //     cout << "isItem1 : 0" <<endl;
    // }
    items_flag |= item1;
    if (items_flag & item1) {  // & 연산의 경우 피연산자의 1인 부분만 계산한다.
        cout << "isItem1 : 1" << endl;
    } else {
        cout << "isItem1 : 0" << endl;
    }

    // getItems
    items_flag = 0;
    items_flag |= (item2 | item3);
    cout << bitset<8>(items_flag) << endl;

    // 비트마스크 : 마스킹 테이프(필요한 작업 내용을 선택할 수 있음)
    constexpr unsigned int red = 0xFF0000;
    constexpr unsigned int green = 0x00FF00;
    constexpr unsigned int blue = 0x0000FF;
    constexpr unsigned int pixel_color = 0xDAA520;
    // argb
    cout << bitset<32>(pixel_color) << endl;
    // 비트 연산자 우선순위는 항상 낮음
    unsigned int redColor = (pixel_color & red) >> 16;
    unsigned int greenColor = (pixel_color & green) >> 8;
    unsigned int blueColor = pixel_color & blue;

    cout << "red : " << bitset<8>(redColor) << endl;
    cout << "green : " << bitset<8>(greenColor) << endl;
    cout << "blue : " << bitset<8>(blueColor) << endl;
    return 0;
}