#include <iostream>

using namespace std;
int main() {
    int fibonacci[12] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    for (int num : fibonacci) {
        num = 1;
        // num = 1;  // num은 복사본이므로 원본 배열은 변경되지 않음}
    }
    for (int num : fibonacci) {
        cout << num << " ";
    }
    for (int &num : fibonacci) {
        num = 1;
    }
    for (int num : fibonacci) {
        cout << num << " ";
    }
    // 동적 할당 배열에는 쓰기가 힘든데 걍 벡터쓰자
    return 0;
}