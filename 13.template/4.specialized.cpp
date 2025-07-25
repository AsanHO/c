/*
4.specialized.cpp
*/

#include <iostream>

using namespace std;

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}
template <>
char getMax<char>(char a, char b) {
    cout << "Specialized version for char called." << endl;
    return (a > b) ? a : b;
}

template <class T>
class Storage {
   private:
    T m_value;

   public:
    Storage(T value) : m_value(value) {}
    ~Storage() {}
    void print() { cout << "Value: " << m_value << endl; }
};

template <>
void Storage<string>::print() {
    cout << "Specialized print for string: " << m_value << endl;
}
template <>
void Storage<double>::print() {
    cout << scientific << m_value << endl;
}

int main() {
    cout << getMax<int>(10, 20) << endl;  //<int>는 선택
    cout << getMax('a', 'b') << endl;     //<int>는 선택

    Storage<int> intStorage(42);
    intStorage.print();

    Storage<double> doubleStorage(3.14);
    doubleStorage.print();

    Storage<string> stringStorage("Hello");
    stringStorage.print();

    return 0;
}