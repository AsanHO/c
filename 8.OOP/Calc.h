#pragma once
#include <iostream>
// using namespace std; 헤더에서는 좋지 않은 코드
class Simple {
   private:
    int m_id;

   public:
    Simple(const int& id);

    void setId(const int& id);
    void display();

    Simple& add(const int& id);
    Simple& sub(const int& id);
    Simple& mul(const int& id);
};
