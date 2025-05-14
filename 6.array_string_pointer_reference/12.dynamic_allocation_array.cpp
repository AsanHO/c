#include <iostream>

// 정적배열 : 사이즈가 컴파일 타임에 결정
// 동적배열 : 사이즈가 런타임에 유동적으로 결정
using namespace std;
int main() {
    int length;

    cin >> length;

    int arr[length];  // 가변길이 배열
    // 위험하므로 위의 방법은 사용하지 말 것
    int* arr2 = new int[length]{11, 22, 34};  // 동적배열
    // int* arr2 = new int[]{11, 22, 34};
    //  사이즈와 초기값을 지정할 때는 서로 싱크가 맞아야 한다.
    //  위의코드는 컴파일 에러 발생

    for (int i = 0; i < length; i++) {
        cout << arr2[i] << endl;
    }

    return 0;
}