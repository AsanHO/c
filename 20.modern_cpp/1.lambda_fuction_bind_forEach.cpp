/*
1.lambda_fuction_bind_forEach

현대 문법은 특히 GUI에 빨리 반영되는 경향이 있다.
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void goodbye(const string& s) { cout << "hello" << s << endl; }

class Object {
   public:
    void hello(const string& s) { cout << "hello" << s << endl; }
};

int main() {
    auto func = [](const int& i) -> void { cout << "Hello World!" << endl; };
    func(123);
    [](const int& i) -> void { cout << i << endl; }(1234);
    {
        string name = "Uno";
        cout << &name << " : " << name << endl;
        [&]() { cout << &name << " : " << name << endl; }();  // name을 레퍼런스로 가져옴
        [=]() { cout << &name << " : " << name << endl; }();  // name을 복사해서 가져옴
    }

    {
        vector<int> v;
        v.push_back(1201);
        v.push_back(232);

        // case 1
        auto func2 = [](int val) { cout << val << endl; };
        for_each(v.begin(), v.end(), func2);
        // case 2 : 더 일반적인 패턴
        for_each(v.begin(), v.end(), [](int val) { cout << val << endl; });

        cout << []() -> int { return 1; } << endl;
    }

    {
        std::function<void(int)> func3 = func;
        func(23);

        function<void()> func4 = std::bind(func, 456);
        func4();
    }
    {
        Object obj;
        auto f = bind(&Object::hello, &obj, std::placeholders::_1);

        f(string("world"));
        auto f2 = bind(&goodbye, std::placeholders::_1);

        f2("world2");
    }
    return 0;
}