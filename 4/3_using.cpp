// 컴파일러는 이름이 같으면 어떻게

#include <iostream>

namespace a {
int av = 10;
}

namespace b {
int av = 20;
int bv = 20;
}  // namespace b
int main() {
    // using namespace std;
    //  cout만 불러올수도 있음 잘은 안쓴다.
    using std::cout;
    using std::endl;

    using namespace a;
    using namespace b;

    cout << "Hello " << a::av << endl;
    cout << "Hello " << bv << endl;
    // 중복된 이름이 있는경우 위와같이 쓰거나
    // 밑과같이 아에 분리를 해야한다. 귀찮을듯
    // {
    //     using namespace b;
    //     cout << "Hello " << av << endl;
    // }
    // {
    //     using namespace b;
    //     cout << "Hello " << av << endl;
    // }

    // 결론적으로 using을 쓸때는 영향도와 모호성을 잘 생각해야하며 trade-off가
    // 일어남을 알아두자
}
