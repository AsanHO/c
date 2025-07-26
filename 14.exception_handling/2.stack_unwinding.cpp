/*
2.stack_unwinding.cpp
*/
#include <iostream>

using namespace std;
void last() {  // int 타입의 예외만 던질 수 있음
    cout << "last() Start" << endl;
    cout << "Throws exception" << endl;
    throw -1;
    cout << "last() End" << endl;  // 이 코드는 실행되지 않음
}
void third() {
    cout << "third() Start" << endl;
    last();
    cout << "third() End" << endl;  // 이 코드는 실행되지 않음
}

void second() {
    cout << "second() Start" << endl;
    try {
        third();
    } catch (double) {
        cout << "second() Caught an exception!" << endl;
        throw;  // 예외를 다시 던짐
    }
    cout << "second() End" << endl;  // 이 코드는 실행되지 않음
}

void first() {
    cout << "first() Start" << endl;
    try {
        second();
    } catch (int) {
        cout << "first() Caught an exception!" << endl;
    }
}

int main() {
    cout << "main() Start" << endl;
    try {
        first();
    } catch (int) {
        cout << "main() Caught an exception!" << endl;
    } catch (...) {  // 모든 예외를 잡는 catch 블록
        cout << "main() Caught an unknown exception!" << endl;
    }
    cout << "main() End" << endl;

    return 0;
}