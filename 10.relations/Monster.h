#pragma once

#include <string>

#include "Position2D.h"

class Monster {
   private:
    std::string m_name;
    Position2D m_location;  // composition관계!! 포지션은 몬스터의 일부(필수)다.
                            // int m_x;
                            // int m_y;

   public:
    Monster(const std::string& name, const Position2D& position_in) : m_name(name), m_location(position_in) {}

    void moveTo(const Position2D& pos_target) {
        // m_x = x_target;
        // m_y = y_target;
        m_location.set(pos_target);
    }

    friend std::ostream& operator<<(std::ostream& out, const Monster& monster) {
        out << "Monster Name: " << monster.m_name << monster.m_location << std::endl;
        return out;
    }
};