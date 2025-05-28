/*
2.IO
*/
#include <iostream>

using namespace std;
class Point {
   private:
    double m_x, m_y, m_z;

   public:
    Point(double x = 0, double y = 0, double z = 0) : m_x(x), m_y(y), m_z(z) {}

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

    void print() {
        cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")" << endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << "(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Point& p) {
        in >> p.m_x >> p.m_y >> p.m_z;
        return in;
    }
};

int main() {
    Point p1(1.0, 2.0, 3.0);
    Point p2(4.0, 5.0, 6.0);

    p1.print();  // Point(1, 2, 3)
    p2.print();  // Point(4, 5, 6)

    cout << p1 << " " << p2 << endl;  // p1: (1, 2, 3)

    //!!! << p1 과 << p2는 오버로딩된 연산자고,
    // << " " 이랑 << endl은 기본 연산자로 컴파일러가 해석한다.

    Point p3, p4;
    cin >> p3 >> p4;  // 사용자로부터 Point 객체 입력 받기

    cout << p3 << p4 << endl;  // 입력된 포인트 출력
}