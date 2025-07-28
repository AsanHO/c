#pragma once

#include <iostream>

// std::auto_ptr<int>; // c++98, c++ 11 deprecated 모던 c++에서는 쓰지 않음

template <class T>
class AutoPtrV2 {
   public:
    T *m_ptr = nullptr;

   public:
    AutoPtrV2(T *ptr = nullptr) : m_ptr(ptr) {
        std::cout << "AutoPtrV2 default constructor" << std::endl;
    }
    ~AutoPtrV2() {
        std::cout << "AutoPtrV2 destructor" << std::endl;
        if (m_ptr != nullptr) delete m_ptr;
    }

    AutoPtrV2(AutoPtrV2 &a) {
        std::cout << "AutoPtrV2 copy constructor" << std::endl;
        // m_ptr = a.m_ptr;

        // deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    AutoPtrV2 &operator=(const AutoPtrV2 &a) {
        std::cout << "AutoPtrV2 copy assignment" << std::endl;
        if (&a == this) return *this;

        // delete m_ptr;
        // m_ptr = a.m_ptr;
        // a.m_ptr = nullptr;
        if (m_ptr != nullptr) delete m_ptr;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
        return *this;
    }

    // move assignment
    /*
    &&로 잡은 매개변수는 메모리에 자리잡은게 아니라 잠깐 생겼다 사라질 의미가
    된다.
    */
    AutoPtrV2(AutoPtrV2 &&a) : m_ptr(a.m_ptr) {
        a.m_ptr = nullptr;  // R-value라서 굳이 필요하진 않지만 깔끔하니까!

        std::cout << "AutoPtr move constructor" << std::endl;
    }

    AutoPtrV2 &operator=(AutoPtrV2 &&a) {
        std::cout << "AutoPtr move assignment" << std::endl;
        if (&a == this) return *this;
        if (!m_ptr) delete m_ptr;

        // shallow copy
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;  // R-value라서 굳이 필요하진 않지만 깔끔하니까!

        return *this;
    }
    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};
