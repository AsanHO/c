#pragma once

#include <iostream>
#include <string>

class Student {
   private:
    std::string m_name;
    int m_intel;

    // TODO : add more members like address, phone, fav food, habits...

   public:
    Student(const std::string& name_in = "No Name", const int& intel_in = 0) : m_name(name_in), m_intel(intel_in) {}

    void setName(const std::string& name_in) { m_name = name_in; }

    void setIntel(const int& intel_in) { m_intel = intel_in; }

    int getIntel() { return m_intel; }
    // 상속과 템플릿을 배우면 코딩량이 적어진다. 뒤로갈수록 코딩 속력이 더 빨라진다.

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << student.m_name << " " << student.m_intel << std::endl;
        return out;
    }
};
