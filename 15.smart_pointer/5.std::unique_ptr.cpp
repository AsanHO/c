/*
5.std::unique_ptr.cpp
포인터가 가리키고 있는 데이터의 소유권이 한곳에만 속할 경우에만 사용하는 스마트
포인터
*/
#include <memory>
#include <string>

#include "AutoPtrV2.h"
#include "ResourceV2.h"
using namespace std;

void func(std::unique_ptr<ResourceV2> &res) { res->setAll(10); }
// 매개변수가 &가 아니면 거부된다. 아니면 r-value를 넣던가
void func2(std::unique_ptr<ResourceV2> res) { res->setAll(10); }
int main() {
    // {
    //     // ResourceV2 *res = new ResourceV2(1000000);
    //     // delete안하면 메모리 누수

    //     std::unique_ptr<ResourceV2> res(new ResourceV2(10000000));
    // }

    {
        std::unique_ptr<int> upi(new int);
        // std::unique_ptr<ResourceV2> res1(new ResourceV2);
        auto res1 = std::make_unique<ResourceV2>(5);

        res1->setAll(5);
        res1->print();

        std::unique_ptr<ResourceV2> res2;

        cout << std::boolalpha;
        cout << static_cast<bool>(res1) << endl;
        cout << static_cast<bool>(res2) << endl;

        // res2 = res1; // unique ptr은 복사가 안됨 copy semantics
        res2 = std::move(res1);  // move semantics
        cout << std::boolalpha;
        cout << static_cast<bool>(res1) << endl;
        cout << static_cast<bool>(res2) << endl;

        if (res1 != nullptr) res1->print();
        if (res2 != nullptr) res2->print();
    }

    {
        cout << "2번째 예제" << endl;
        auto res1 = std::make_unique<ResourceV2>(5);
        res1->setAll(1);
        res1->print();

        func(res1);

        res1->print();
    }
    {
        cout << "3번째 예제" << endl;

        auto res1 = std::make_unique<ResourceV2>(5);
        res1->setAll(1);
        res1->print();

        cout << std::boolalpha;
        cout << static_cast<bool>(res1) << endl;

        // res1 =func2(std::move(res1));
        func2(std::move(res1));
        cout << std::boolalpha;
        cout << static_cast<bool>(res1) << endl;
    }

    // {
    //     cout << "bad case 1" << endl;
    //     ResourceV2 *res = new ResourceV2;
    //     std::unique_ptr<ResourceV2> res1(res);
    //     std::unique_ptr<ResourceV2> res2(res);

    //     delete res;
    // }

    return 0;
}