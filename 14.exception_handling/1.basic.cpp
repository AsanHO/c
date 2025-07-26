/*
1.basic.cpp
훌륭한 프로그래머는 정상적인 상황 뿐만아니라, 비정상적인 상황에서도 프로그램이 잘 동작하도록 예외 처리를 한다.
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int findFirstChar(const char *str, char ch) {
    for (std::size_t i = 0; i < strlen(str); ++i) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
    // 이경우 사용자나 프로그래머가 정상적이지 않은 상황에 -1이라는 점을 숙지해야한다는 불편한점이 있다.
}

double divide(int x, int y, bool &success) {
    if (y == 0) {
        success = false;
        return 0.0;
    }
    success = true;
    return static_cast<double>(x) / y;
}

int main() {
    bool success;
    double result = divide(5, 3, success);
    if (!success) {
        cout << "Division by zero error!" << endl;
    } else {
        cout << "5 / 3 = " << result << endl;
    }

    std::ifstream file("example.txt");
    if (!file) {
        std::cerr << "File not found!" << std::endl;
    }
    /*
    반드시 예외처리를 해야하는 것은 아니며,
    오히려 예외처리가 프로그램의 성능을 저하시킬수 있는 측면도 있다.
    따라서 유연하고 유동적으로 예외처리를 하는 것이 좋다.
    */
    double x;
    x = -1.0;
    try {
        if (x < 0.0) throw string("Negative input not allowed");
        cout << std::sqrt(x) << endl;
    } catch (std::string error_message) {  // auto casting안됨 예외처리는 형변환이 엄격함
        cout << "Error: " << error_message << endl;
    }
    return 0;
}