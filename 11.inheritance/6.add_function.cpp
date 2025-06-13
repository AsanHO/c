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

int main() { return 0; }