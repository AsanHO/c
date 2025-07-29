/*
3.string_length_capacity.cpp
길이와 용량에 대해서 알아본다.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string my_str = "01234567";

    cout << my_str.size() << endl;
    // string은 char과 달리 \0캐릭터를 인식하지 않는다.
    // 이유 -> 클래스의 속성으로 이미 커스텀 되어있으므로,
    // 때문에 널캐릭터를 별도로 관리하지 않는다.

    cout << std::boolalpha;
    cout << my_str.empty() << endl;
    cout << my_str.capacity() << endl;
    // string도 vector와 마찬가지로 reallocation을 피하기 위해
    // 미리 capa를 늘려놓는다.
    my_str.reserve(1000);
    cout << my_str.capacity() << endl;
    cout << my_str.max_size() << endl;
}