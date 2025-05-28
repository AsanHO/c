/*
7.parentesis 함수객체(functor)
*/

#include <iostream>

using namespace std;

class Accumulator {
   private:
    int m_counter = 0;

   public:
    // 함수 객체로서의 오버로딩
    int operator()(int value) { return m_counter += value; }
};

int main() {
    Accumulator acc;

    cout << acc(10) << endl;  // 10
    cout << acc(20) << endl;  // 30
    cout << acc(30) << endl;  // 60

    return 0;
}