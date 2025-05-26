/*
14.nested_types
*/
#include <iostream>
using namespace std;

class Fruit {
   public:
    enum FruitType { APPLE, BANANA, ORANGE };
    enum class FruitTypeClass { STARFRUIT, GRAPE, PINEAPPLE };

   private:
    FruitType m_type;             // FruitType 열거형을 사용하여 과일 종류를 저장
    FruitTypeClass m_type_class;  // FruitType 열거형을 사용하여 과일 종류를 저장
   public:
    Fruit(FruitType type) : m_type(type) {}                       // 생성자에서 과일 종류를 초기화
    Fruit(FruitTypeClass type) : m_type_class(type) {}            // 생성자에서 과일 종류를 초기화
    FruitType getType() const { return m_type; }                  // 과일 종류를 반환하는 멤버 함수
    FruitTypeClass getTypeClass() const { return m_type_class; }  // 과일 종류를 반환하는 멤버 함수
};

int main() {
    Fruit apple = Fruit(Fruit::APPLE);  // APPLE 타입의 Fruit 객체 생성
    if (apple.getType() == Fruit::APPLE) {
        cout << "This is an apple." << endl;  // 과일 종류가 APPLE이면 출력
    }
    Fruit starfruit = Fruit(Fruit::FruitTypeClass::STARFRUIT);  // STARFRUIT 타입의 Fruit 객체 생성
    if (starfruit.getTypeClass() == Fruit::FruitTypeClass::STARFRUIT) {
        cout << "This is a starfruit." << endl;  // 과일 종류가 STARFRUIT이면 출력
    }

    return 0;
}