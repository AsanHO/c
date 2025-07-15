/*
6.add_function.cpp
*/
#include <iostream>

class Base {
   protected:
    int m_value;
    Base(const int& value) : m_value(value) {}
};

class Derived : public Base {
   public:
    Derived(const int& value) : Base(value) {}
    void setValue(int value) { Base::m_value = value; }
};

int main() {
    int result = (2782080 + 2782080 + 3386520 + 2315940 + 582262 + +1680000 +
                  1920000 + 2040000 + 1920000 + 1920000) /
                 9;
    std::cout << result;
    return 0;
}