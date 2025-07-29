/*
6.exception_danger_thing.cpp
예외처리의 단점과 위험성에 대해서 알아본다.
기본적으로 if else보다는 페널티(속도)가 있으며,
모든 오류(주로 예상할수 있는 오류에)를 트라이캐치를 사용하지 말자.
논리적으로 대책을 마련하기 어려운 경우 사용하자.
*/
#include <iostream>
#include <memory>
using namespace std;

class A {
   public:
    ~A() { throw "error"; }
    // 소멸자에서 throw를 던질수 없다.
};
int main() {
    try {
        int* i = new int[100000];
        unique_ptr<int> up_i(i);  // 스마트 포인터 첫 만남 (알아서 delete해줌)
        throw "error";
        // 메모리 누수 발생!!!!!
        delete[] i;
    } catch (...) {
        cout << "Catch" << endl;
    }
    return 0;
}
