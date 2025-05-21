/*
16.ellipsis
잘 사용하지는 않는다.
*/
#include <cstdarg>  // va_list, va_start, va_arg, va_end
#include <iostream>

using namespace std;

double findAverage(int count, ...) {
    // 가변인자 함수
    // count는 인자의 개수
    // ...은 가변인자를 의미한다.
    // va_list는 가변인자를 처리하기 위한 자료형이다.
    // va_start는 가변인자를 초기화하는 함수이다.
    // va_arg는 가변인자를 가져오는 함수이다.
    // va_end는 가변인자를 종료하는 함수이다.
    va_list args;
    double sum = 0.0;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        double target = va_arg(args, int);
        cout << i << " : " << target << endl;
        sum += target;
    }
    va_end(args);
    cout << "sum: " << sum << endl;
    return sum / count;
}
int main() {
    // 가변인자 함수는 인자의 개수가 정해져 있지 않은 함수이다.
    // 가변인자 함수를 사용할 때는
    // 인자의 개수를 첫 번째 인자로 전달해야 한다.
    cout << findAverage(3, 1, 2, 3) << endl;
    cout << findAverage(4, 1, 2, 3, 4) << endl;
    cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
    cout << findAverage(11, 1, 2, 3, 4, 5) << endl;
}
