/*
1.move_semantics_smtptr.cpp
c/c++언어의 가장 번거로운 점은 동적할당에서 new와 delete를 일일히
지정해주어야한다는 것이다. 현대 c++에서는 스마트 포인터를 도입해서 불편한 점을
상당 부분 개선했다. 스마트포인터의 개념과 구조를 이해하기 위해서는 이동이라는
것이 무엇인지 알아야한다.
*/

#include <iostream>

#include "AutoPtr.h"
#include "Resource.h"

using namespace std;

// RAII : resource acquisition is initialization 자원 획득 즉시 초기화

void func() {
    Resource *res = new Resource;
    AutoPtr<Resource> res2 = new Resource;

    if (true) {
        return;
    }
    delete res;

    return;
}
int main() {
    // func();

    // 오토포인터의 한계 :: 소유권 문제
    AutoPtr<Resource> res1(new Resource);
    AutoPtr<Resource> res2;

    cout << std::boolalpha;

    cout << res1.m_ptr << endl;
    cout << res2.m_ptr << endl;

    res2 = res1;  // move sematics
    /*
    그동안의 =
    1. 값 복사 (집키가 두개)
    2. 값 참조 (집키가 하나지만 소유권은 원조맛집)
    move semantics
    - 이동 (집키가 하나지만 1호점이 아닌, 2호점이 소유)
     */

    cout << res1.m_ptr << endl;
    cout << res2.m_ptr << endl;  // destructor가 두번 실행된다!! -> 런타임 에러
    // copy constructor가 필요

    return 0;
}