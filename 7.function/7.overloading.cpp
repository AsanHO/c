/*
7.overloading
똑같은 이름의 함수를 만들 수 있다.
그런데 오버로딩을 굳이 할 필요는 없다.
*/
#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int main() {
    int a = 5, b = 10;
    double c = 5.5, d = 10.5;
    cout << "Int add: " << add(a, b) << endl;
    cout << "Double add: " << add(c, d) << endl;
    return 0;
}