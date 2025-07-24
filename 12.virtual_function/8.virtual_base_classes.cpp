/*
8.virtual_base_classes_with_the_diamond_problem.cpp

이 예제에서는 가상 상속을 사용하여 다이아몬드 문제를 해결하는 방법을 학습한다.
다이아몬드 문제란 두 개의 부모 클래스가 동일한 기본 클래스를 상속받고,
그 두 부모 클래스를 자식 클래스가 상속받을 때 발생하는 모호성이다.
b extend a
c extend a
d extend b, c
구현 시 d가 a의 멤버에 접근할 때, b와 c 중 어떤 것을 통해 접근해야 할지 모호해진다.
가상 상속을 사용하면 이 문제를 해결할 수 있다.

*/
#include <iostream>
using namespace std;
class PoweredDevice {
   public:
    int m_i;
    PoweredDevice(int power) { cout << "PoweredDevice(int i) called with " << power << endl; }
};

class Scanner : virtual public PoweredDevice {
   public:
    Scanner(int scanner, int power) : PoweredDevice(power) { cout << "Scanner(int i) called with " << power << endl; }
};

class Printer : virtual public PoweredDevice {
   public:
    Printer(int printer, int power) : PoweredDevice(power) { cout << "Printer(int i) called with " << power << endl; }
};

class Copier : public Scanner, public Printer {
   public:
    Copier(int scanner, int printer, int power) : Scanner(scanner, power), Printer(printer, power), PoweredDevice(power) {
        cout << "Copier(int copier, int scanner, int printer, int power) called with " << power << endl;
    }
};

int main() {
    Copier copier(1, 2, 3);
    cout << "PoweredDevice m_i: " << &copier.Scanner::PoweredDevice::m_i << endl;  // Scanner를 통해 접근
    cout << "PoweredDevice m_i: " << &copier.Printer::PoweredDevice::m_i << endl;  // Printer를 통해 접근
    return 0;
}