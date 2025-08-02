/*
6.std::shared_ptr.cpp
std::shared_ptr의 경우 자기가 몇 군데에서 사용되는 중인지 세게 된다.
*/

#include <iostream>
#include <memory>

#include "ResourceV2.h"

int main() {
    // 위 패턴은 위험함
    ResourceV2 *res = new ResourceV2(3);
    res->setAll(1);
    std::shared_ptr<ResourceV2> ptr1(res);

    ptr1->print();

    {
        std::shared_ptr<ResourceV2> ptr2(ptr1);

        auto ptrV1 =
            std::make_shared<ResourceV2>(3);  // 실제로 자주사용하는 패턴
        ptrV1->setAll(3);
        ptrV1->print();

        ptr2->setAll(3);
        ptr2->print();
        std::cout << "Going out of the block" << std::endl;
    }

    ptr1->print();
    std::cout << "Going out of the outer block" << std::endl;
    return 0;
}