/*
6.partial_specilization.cpp
*/
#include <iostream>
#include <string>

using namespace std;

template <typename T, int size>
class StaticArray {
   private:
    T m_array[size];

   public:
    T* getArray() { return m_array; }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return m_array[index];
    }
};

template <typename T, int size>

void print(StaticArray<T, size>& arr) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <int size>
void print(StaticArray<char, size>& arr) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == '\0') {
            break;  // Stop printing at null terminator
        }
        cout << arr[i];
    }
}
int main() {
    StaticArray<int, 5> intArray;
    for (int i = 0; i < 5; ++i) {
        intArray[i] = i * 10;
    }
    print(intArray);

    StaticArray<char, 14> charArray;
    for (int i = 0; i < 14; ++i) {
        charArray[i] = 'A' + i;
    }
    strcpy(charArray.getArray(), "HelloWorld!");
    print(charArray);

    return 0;
}
// 메소드에서도 부분 특수화를 사용할 수 있지만 생략