#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[3] = {1, 2, 3};
    int * c = a; //int[n] 과 int의 타입은 서로 다르다. 근데 역참조연산자를 사용할 수 있다..??
    cout << c << "\n";  
    cout << *c << "\n";  //0x16ae9f488 &a를 하지 않았는데 가능한가..??
    cout << &a[0] << "\n"; //0x16ae9f488
    cout << *&a[0] << "\n"; //0x16ae9f488
    cout << c + 1 << "\n"; //0x16ae9f48c
    cout << &a[1] << "\n"; //0x16ae9f48c
    return 0;
}