#include <iostream>

// user defined data types
// 대부분은 헤더에 선언하긴함.
// 많이 사용하는 편
enum Color {
    // COLOR_WHITE = -2,
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
};

enum Feel {
    HAPPY,
    JOY,
    // ⛔️COLOR_BLUE,
};

int computeDamage(int weapon_id) {
    if (weapon_id == 0) {
        return 12;
    }
    if (weapon_id == 1) {
        return 5;
    }
    return 0;
}

using namespace std;
int main() {
    cout << "hello" << endl;
    Color paint = COLOR_BLACK;
    cout << paint << " " << COLOR_BLACK << endl;
}