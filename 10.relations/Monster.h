#pragma once

#include <iostream>
#include <string>

class Monster {
   private:
    std::string m_name;
    int m_x;
    int m_y;

   public:
    Monster(const std::string& name, const int x, const int y)
        : m_name(name), m_x(x), m_y(y) {}

    void moveTo(const int& x_target, const int& y_target) {
        m_x = x_target;
        m_y = y_target;
    }

    friend std::ostream& operator<<(std::ostream& out, const Monster& monster) {
        out << "Monster Name: " << monster.m_name << ", Position: ("
            << monster.m_x << ", " << monster.m_y << ")" << std::endl;
        return out;
    }
};