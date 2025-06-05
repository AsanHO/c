#pragma once

#include <iostream>
class Position2D {
   private:
    int m_x;
    int m_y;

   public:
    Position2D(const int& x_in, const int& y_in) : m_x(x_in), m_y(y_in) {}

    // 밑의 코드 혹은 = 오퍼레이터를 오버로딩하면 된다.
    void set(const Position2D& pos_target) { set(pos_target.m_x, pos_target.m_y); }

    void set(const int& x_target, const int& y_target) {
        m_x = x_target;
        m_y = y_target;
    }

    friend std::ostream& operator<<(std::ostream& out, const Position2D& position) {
        out << ", Position: (" << position.m_x << ", " << position.m_y << ")" << std::endl;
        return out;
    }
};