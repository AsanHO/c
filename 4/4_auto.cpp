#include <iostream>
using namespace std;

auto addItem(int a, int b) { return a + b; }
auto addItem(double a, double b) { return a + b; }
// 위와 같이 오토함수는 파라미터까지는 오토로 할수 없다. 다만 위와 같이 똑같은
// 이름으로 만들면 알아서 컴파일러가 추론함
// so, c++17에서는 template 사용 -> 이후과정에서 설명

int main() {
    auto a = 1.2;
    auto b = 2;
    auto c = 2 + a;  // double

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;

    auto r1 = addItem(1, 2);
    auto r2 = addItem(3.5, 3.1);

    cout << r1 << endl;
    cout << r2 << endl;
}