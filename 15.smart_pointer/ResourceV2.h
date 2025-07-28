#pragma once

#include <iostream>

class ResourceV2 {
   public:
    int *m_data = nullptr;
    unsigned m_length = 0;

   public:
    ResourceV2() { std::cout << "ResourceV2 constructed" << std::endl; }
    ResourceV2(unsigned length) {
        std::cout << "ResourceV2 constructed" << std::endl;
        this->m_data = new int[length];
        this->m_length = length;
    }

    ResourceV2(const ResourceV2 &res) {
        std::cout << "ResourceV2 constructed" << std::endl;
        ResourceV2(res.m_length);
        for (unsigned i = 0; i < m_length; ++i) m_data[i] = res.m_data[i];
    }
    ~ResourceV2() {
        std::cout << "ResourceV2 destructed" << std::endl;
        if (m_data != nullptr) delete[] m_data;
    }
    ResourceV2 &operator=(ResourceV2 &res) {
        std::cout << "ResourceV2 copy assignment" << std::endl;
        if (&res == this) return *this;
        if (this->m_data != nullptr) delete[] m_data;
        m_length = res.m_length;
        m_data = new int[m_length];

        for (unsigned i = 0; i < m_length; ++i) m_data[i] = res.m_data[i];

        return *this;
    }

    void print() {
        for (unsigned i = 0; i < m_length; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    void setAll(const int &v) {
        for (unsigned i = 0; i < m_length; ++i) {
            m_data[i] = v;
        }
    }
};
