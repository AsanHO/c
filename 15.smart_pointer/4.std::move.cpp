/*
4.std::move.cpp
*/
#include <string>

#include "AutoPtrV2.h"
#include "ResourceV2.h"
using namespace std;

template <class T>
void Myswap(T &a, T &b) {
    // T tmp = a;
    // a = b;
    // b = tmp;

    T tmp{std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}
int main() {
    // {
    //     AutoPtrV2<ResourceV2> res1 = new ResourceV2(10000000);
    //     cout << res1.m_ptr << endl;

    //     // AutoPtrV2<ResourceV2> res2 = res1;  // deepcopy
    //     AutoPtrV2<ResourceV2> res2 = std::move(res1);  // move ->
    //     R-value로사용

    //     cout << res1.m_ptr << endl;  // nullptr이 되보림
    //     cout << res2.m_ptr << endl;
    // }

    // {
    //     AutoPtrV2<ResourceV2> res1(new ResourceV2(3));
    //     res1->setAll(3);
    //     AutoPtrV2<ResourceV2> res2(new ResourceV2(5));
    //     res2->setAll(5);

    //     res1->print();
    //     res2->print();

    //     Myswap(res1, res2);

    //     res1->print();
    //     res2->print();
    // }

    {
        vector<string> v;
        string str = "Hello";

        v.push_back(str);
        cout << str << endl;
        cout << v[0] << endl;

        v.push_back(std::move(str));

        cout << str << endl;  // "r-value로 써서 공백이 되버림ㅋㅋㅋ"
        cout << v[0] << " " << v[1] << endl;
    }
}