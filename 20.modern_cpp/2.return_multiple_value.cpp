/*
2.return_multiple_value.cpp
c++17전용
*/
#include <iostream>

using namespace std;

tuple<int, int> classicFunc() { return tuple<int, int>(123, 456); }
auto mdFunc() { return tuple(123, 456, 293, 192); }
int main() {
    cout << "Hello world" << endl;
    auto result = mdFunc();
    cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << " " << endl;

    auto [a, b, c, d] = mdFunc();
    return 0;
}