#include <bits/stdc++.h>

#include <iomanip>
// 부동소수점은 사용할 때 주의사항에 집중할 것. 오류가 빈번함.
int main() {
    using namespace std;

    float f;
    double d;
    long double ld;

    cout << sizeof(f) << "\n";
    cout << sizeof(d) << "\n";
    cout << sizeof(ld) << "\n";

    // 자료형의 최댓값
    cout << numeric_limits<float>::max() << "\n";
    cout << numeric_limits<double>::max() << "\n";
    cout << numeric_limits<long double>::max() << "\n";

    // 자료형의 최솟값
    cout << numeric_limits<float>::min() << "\n";
    cout << numeric_limits<double>::min() << "\n";
    cout << numeric_limits<long double>::min() << "\n";

    cout << 3.14e-1 << "\n";
    cout << 3.14e1 << "\n";
    cout << 3.14e2 << "\n";
    cout << 3.14e-2 << "\n";

    // 출력형식 변경 부동소수점 오류 유도
    cout << setprecision(20) << "\n";
    cout << 1 / 0.3 << endl;

    return 0;
}