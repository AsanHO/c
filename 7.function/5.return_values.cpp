/*
5.return_values
*/
#include <array>
#include <iostream>
#include <tuple>
using namespace std;
/*
return by address
*/
int* getValue(int x) {
    int value = x * 2;
    return &value;  // Returning address of local variable
}
int* allocateMemory(int size) { return new int[size]; }
/*
return by reference
*/
int& getReference(int x) {
    int value = x * 2;
    return value;
}

int& get(std::array<int, 100>& arr, int index) { return arr[index]; }

/*
return multiple values :: 올드스쿨C,directX에서 많이 나오는 패턴
*/
struct S {
    int a, b, c, d;
};
S getStruct() {
    S my_s{1, 2, 3, 4};
    return my_s;
}

std::tuple<int, double> getTuple() {
    int a = 10;
    double b = 3.14;
    return std::make_tuple(a, b);
}
int main() {
    // wrong case 1
    int value = *getValue(5);
    cout << "Value: " << value << endl;
    // 위 코드는 지역 변수를 반환하는 함수의 예시.
    // 지역 변수는 함수가 종료되면 메모리에서 해제되므로, 반환된 포인터를
    // 사용하면 예기치 않은 동작이 발생할 수 있다.
    // 지역 변수를 반환하는 것은 안전하지 않습니다. 올바른 방법은
    // 동적 메모리를 사용하거나, 참조를 반환하는 것이다.
    // 다른해설 ⬇️
    // 함수앞의 *는 포인터를 역참조하여 값을 가져오는 것을 의미합니다.
    // 하지만 getValue 함수는 지역 변수의 주소를 반환하므로,
    // 이 주소는 함수가 종료되면 유효하지 않게 됩니다.

    // good case 1
    // int* array = new int[10];
    int* array = allocateMemory(10);

    // wrong case 2
    int value2 = getReference(5);
    cout << "Value2: " << value2 << endl;
    cout << "Value2: " << value2 << endl;  // 위 실행부터 value2가 사라져서 쓰레기값이 될 수 있다.
    cout << "Value2: " << value2 << endl;

    // good case 2 : 메모리가 잡혀 있는 경우에는 사용해도 좋다.
    std::array<int, 100> arr;
    arr[30] = 10;
    get(arr, 30) = 1024;
    cout << "arr[30]: " << arr[30] << endl;

    S my_s = getStruct();
    cout << "my_s.a: " << my_s.a << endl;
    cout << "my_s.b: " << my_s.b << endl;

    std::tuple<int, double> my_tuple = getTuple();
    int a = std::get<0>(my_tuple);
    double b = std::get<1>(my_tuple);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}