/*
2.class_templates
*/
#include <cassert>
#include <iostream>
template <typename T>
class MyArray {
   private:
    int m_length;
    T* m_data;

   public:
    MyArray() {
        m_length = 0;
        m_data = nullptr;
    }

    MyArray(int length) {
        m_length = length;
        m_data = new T[m_length];
    }

    ~MyArray() { reset(); }

    void reset() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    T& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }

    void print() const {
        if (m_data == nullptr || m_length == 0) {
            std::cout << std::endl;
            return;
        }
        for (int i = 0; i < m_length; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyArray<int> arr(5);
    for (int i = 0; i < arr.getLength(); ++i) {
        arr[i] = i * 10;  // 배열에 값 할당
    }
    arr.print();  // 출력: 0 10 20 30 40

    arr.reset();  // 배열 초기화
    arr.print();  // 출력: (빈 줄)

    return 0;
}