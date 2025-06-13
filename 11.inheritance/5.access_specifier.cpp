/*
5.access_specifier.cpp
*/
#include <iostream>

class Base {
   public:
    int m_public;

   protected:
    int m_protected;

   private:
    int m_private;
};

class Derived : public Base {
   public:
    Derived() {
        m_public = 123;
        m_protected = 123;
        // ⛔️
        //  m_private = 123;
    }
};

class DerivedV2 : protected Base {
   public:
    DerivedV2() {
        m_public = 123;
        m_protected = 123;
        // ⛔️
        //  m_private = 123;
    }
};

class DerivedV3 : private Base {
   public:
    DerivedV3() {
        m_public = 123;
        m_protected = 123;
        // ⛔️
        //  m_private = 123;
    }
};

// private -> public 상속된 경우 조부모클래스의 속성을 물려받을 수 없다.
class DerivedV3_1 : public DerivedV3 {
   public:
    DerivedV3_1() {
        // ⛔️
        // m_public = 123;
        // m_protected = 123;
    }
};

int main() {
    Base base;

    base.m_public = 123;
    // ⛔️
    // base.m_protected = 123;
    // base.m_private = 123;

    Derived derived;

    // public 부모를 상속받은 경우
    derived.m_public = 123;
    // ⛔️
    // derived.m_protected = 123;
    // derived.m_private = 123;

    // protected 부모를 상속받은 경우
    DerivedV2 derived2;
    // ⛔️
    // derived2.m_public = 123;
    // derived2.m_protected = 123;
    // derived2.m_private = 123;

    return 0;
}