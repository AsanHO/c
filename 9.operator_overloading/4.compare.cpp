/*
3.compare
*/
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Cents {
   private:
    int m_cents;

   public:
    Cents(int cents = 0) : m_cents(cents) {}
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    friend std::ostream& operator<<(std::ostream& out, const Cents& c) {
        out << c.m_cents << " ";
        return out;
    }

    friend bool operator==(const Cents& c1, const Cents& c2) {
        return c1.m_cents == c2.m_cents;
    }

    friend bool operator<(const Cents& c1, const Cents& c2) {
        return c1.m_cents < c2.m_cents;
    }  // 무조건 < 연산자를 오버로딩해야 한다. std::sort는 < 연산자를 사용하기
       // 때문
};

int main() {
    Cents c1(5);
    Cents c2(10);

    c1 == c2 ? cout << "c1 and c2 are equal" << endl
             : cout << "c1 and c2 are not equal" << endl;  // false

    vector<Cents> arr(20);
    for (unsigned i = 0; i < 20; ++i) {
        arr[i].getCents() = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);  // Shuffle the array

    std::sort(begin(arr), end(arr));

    for (auto& e : arr) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}