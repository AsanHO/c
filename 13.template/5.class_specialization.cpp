/*
5.class_specialization.cpp
*/
#include <iostream>

using namespace std;

template <typename T>
class A {
   public:
    void print() { cout << typeid(T).name() << endl; }
    void test() {}
};

template <>
class A<char> {
   public:
    void print() { cout << "Specialized for char" << endl; }
};

template <typename T>
class Storage8 {
   private:
    T m_array[8];

   public:
    void set(int index, T value) {
        if (index >= 0 && index < 8) {
            m_array[index] = value;
        }
    }
    const T& get(int index) const {
        if (index >= 0 && index < 8) {
            return m_array[index];
        }
        throw out_of_range("Index out of range");
    }
};
template <>
class Storage8<bool> {
   private:
    unsigned char m_data;

   public:
    Storage8() : m_data(0) {}
    void set(int index, bool value) {
        if (index < 0 || index >= 8) {
            throw out_of_range("Index out of range");
        }
        unsigned char mask = 1 << index;
        if (value) {
            m_data |= mask;
        } else {
            m_data &= ~mask;
        }
    }

    bool get(int index) const {
        if (index < 0 || index >= 8) {
            throw out_of_range("Index out of range");
        }
        return (m_data >> index) & 1;
    }
};

int main() {
    A<int> a_int;
    A<double> a_double;
    A<char> a_char;
    a_int.print();     // int
    a_double.print();  // double
    a_char.print();    // char

    // a_char.test();    // Specialized for char
    a_int.test();     // int
    a_double.test();  // double

    Storage8<int> intStorage;
    for (int count = 0; count < 8; ++count) {
        intStorage.set(count, count * 10);
    }
    for (int count = 0; count < 8; ++count) {
        cout << intStorage.get(count) << " ";  // 0 10 20 30 40 50 60 70
    }
    cout << sizeof(Storage8<int>) << endl;  // 4 (int size)

    Storage8<bool> boolStorage;
    for (int count = 0; count < 8; ++count) {
        boolStorage.set(count, count % 2 == 0);  // true for even
    }
    for (int count = 0; count < 8; ++count) {
        cout << boolStorage.get(count) << " ";  // 1 0 1 0 1 0 1 0
    }
    cout << sizeof(Storage8<bool>) << endl;  // 1 (unsigned char size
    return 0;
}