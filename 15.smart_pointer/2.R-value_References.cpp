/*
2.R-value_References.cpp
오른쪽 값 참조
*/

#include <iostream>

using namespace std;
void func(int &lref) { cout << "L-value ref" << endl; }
void func(int &&rref) { cout << "R-value ref" << endl; }
int getResult() { return 100 * 100; }
int main() {
    int x = 5;  // 5는 문장이 끝나면 사라질 운명
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    // L-value references
    int &lr1 = x;  // Modifiable l-values
    // int &lr2 = cx; // Non-Modifiable l-values
    // int &lr3 = 5 //R-values

    const int &lr4 = x;   // Modifiable l-values
    const int &lr5 = cx;  // Non-Modifiable l-values
    const int &lr6 = 5;   // R-values

    // R-value references
    // int &&rr1 = x;   // Modifiable l-values
    // int &&rr2 = cx;  // Non-Modifiable l-values
    int &&rr3 = 5;  // R-values

    // const int &&rr4 = x;   // Modifiable l-values
    // const int &&rr5 = cx;  // Non-Modifiable l-values
    const int &&rr6 = 5;  // R-values

    func(x);
    func(5);
    func(getResult());
}