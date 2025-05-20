/*
11.벡터를 효율적으로 사용하기
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> v{1, 2, 3};

    // size, capacity, 사이즈와 용량
    // 사이즈와 용량은 같은게 아닌가?
    // 용량은 벡터가 할당한 메모리의 크기
    // 사이즈는 벡터에 들어있는 원소의 개수
    /*
    C++ STL의 vector는 push_back()을 통해 배열의 원소를 계속 늘릴 수 있다.
    그러나, vector가 처음 선언될 때 예약되어 있던 '용량'을 초과해버리면,
    그보다 더 '큰' (2배 정도) 용량의 메모리를 할당한 후 기존의 원소를
    모두 복사하고, 기존의 메모리는 해제하는 작업을 거친다.

    이 과정은 매우 비효율적이므로, 벡터를 사용할 때는 미리 예상되는
    원소의 개수만큼 용량을 예약해두는 것이 좋다.

    벡터의 단점을 인간의 미래 예측으로 보완하는 것이라고 볼 수 있다.

    물론 현대에서 보편적인 방법은 아니나 GPU나 빅데이터를 다룰 경우에 필요한
    테크닉들이 되겠다.
    */

    for (auto &e : v) {
        cout << e << "";
    }
    cout << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(4);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.resize(10);  // 사이즈를 10으로 늘림
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.resize(5);  // 사이즈를 5로 줄임
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.reserve(20);  // 용량을 20으로 늘림

    v.push_back(5);
    v.push_back(5);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
}