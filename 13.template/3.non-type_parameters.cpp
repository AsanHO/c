/*
3.non-type_parameters.cpp
*/
#include <cassert>
#include <iostream>
using namespace std;
template <typename T, unsigned int T_size>
class MyArray {
   private:
    T* m_data;

   public:
    MyArray() { m_data = new T[T_size]; }

    ~MyArray() { reset(); }

    void reset() {
        delete[] m_data;
        m_data = nullptr;
    }
    T& operator[](int index) {
        assert(index >= 0 && index < T_size);
        return m_data[index];
    }

    int getLength() const { return T_size; }

    void print() const {
        if (m_data == nullptr || T_size == 0) {
            std::cout << std::endl;
            return;
        }
        for (int i = 0; i < T_size; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // unsigned  i = 100;
    // MyArray<double, i> my_arr2;  // 단, 컴파일타임에 크기가 결정되어야 함
    MyArray<double, 100> my_arr;  // 단, 컴파일타임에 크기가 결정되어야 함
    for (int i = 0; i < 100; ++i) {
        my_arr[i] = i * 1.1;  // 배열에 값 할당
    }
    my_arr.print();  // 출력: 0 1.1 2.2 ... 109.9
}