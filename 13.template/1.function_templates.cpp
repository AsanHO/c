/*
1.function_templates.cpp
프로그래밍 언어에는 프로그래머의 단순 반복 작업을 줄여주기 위한 여러가지 장치들이 존재한다.
그 중 템플릿은 여러가지 자료형에 대해서 거의 비슷한 코드를 반복해서 작성하는 것을 방지해준다.
*/
#include <iostream>
class Cents {
   private:
    int m_cents;

   public:
    Cents(int cents = 0) : m_cents(cents) {}
    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    operator int() const { return m_cents; }  // Cents 객체를 int로 변환하는 타입 캐스트 연산자

    friend std::ostream& operator<<(std::ostream& out, const Cents& c) {
        out << c.m_cents << " cents";
        return out;
    }
};

using namespace std;

// int getMax(int x, int y) { return x > y ? x : y; }

// double getMax(double x, double y) { return x > y ? x : y; }

// float getMax(float x, float y) { return x > y ? x : y; }
// 같은 기능을 하는 함수의 조합이 너 무 많 다.

template <typename Potato>
Potato getMax(Potato x, Potato y) {
    return x > y ? x : y;
}

int main() {
    cout << getMax(10, 20) << endl;                // int
    cout << getMax(10.5, 20.5) << endl;            // double
    cout << getMax(10.5f, 20.5f) << endl;          // float
    cout << getMax('a', 'c') << endl;              // char
    cout << getMax(Cents(10), Cents(20)) << endl;  // Cents

    // 템플릿은 컴파일 타임에 타입을 결정한다.
    // 따라서 템플릿 함수는 오버로딩이 불가능하다.
    // 템플릿 함수는 컴파일 타임에 타입을 결정하기 때문에
    // 런타임에 타입을 결정하는 virtual 함수와는 다르다.

    return 0;
}
