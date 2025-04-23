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

    // 영역 제한 열거형-Scoped Enumerations(열거형 클래스-Enum class)

    enum class LocalColor { RED, BLUE };
    enum class Fruit { BANANA, APPLE };
    LocalColor color = LocalColor::RED;
    Fruit fruit = Fruit::BANANA;
    // 밑의 코드는 enum(non class)일때는, int로 바꾸기 때문에 정상으로 작동됨.
    // 객체지향적으로는 맞지 않는 코드, 객체지향적 사고라면 이넘 클래스 사용할
    // 것 if (color == fruit) {
    //     cout << "hi" << endl;
    // }
}