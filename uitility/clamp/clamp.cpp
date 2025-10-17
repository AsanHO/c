/*
clamp.cpp
값이 -100 과 100으로 가정했을때
-1000이 들어오면 -100으로,
1000이 들어오면 100으로 제한하는 함수.
그래픽스에서 주로 사용함
*/

#include <iostream>
#include <string>

using namespace std;

int clamp(int target, int min, int max) {
    if (target < min) return min;
    if (target > max) return max;
    return target;
}

int main() {
    cout << clamp(50, -100, 100) << endl;
    cout << clamp(-1000, -100, 100) << endl;
    cout << clamp(1000, -100, 100) << endl;
    return 0;
}