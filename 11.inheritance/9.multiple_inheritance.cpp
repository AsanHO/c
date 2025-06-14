/*
9.multiple_inheritance.cpp
부모님이 3명? 그만큼 문제가 생길여지가 있지만 그래도 써야하긴 한다.
특히 다이아몬드 상속이 문제가 될 수 있다.
*/
#include <iostream>
using namespace std;

class USBDevice {
   private:
    long m_id;

   public:
    USBDevice(long id) : m_id(id) {}
    long getID() { return m_id; }
    void plugAndPlay() {}
};
class NetworkDevice {
   private:
    long m_id;

   public:
    NetworkDevice(long id) : m_id(id) {}
    long getID() { return m_id; }
    void networking() {}
};
class USBNetworkDevice : public USBDevice, public NetworkDevice {
   public:
    USBNetworkDevice(long usb_id, long net_id) : USBDevice(usb_id), NetworkDevice(net_id) {}
};
int main() {
    USBNetworkDevice device = USBNetworkDevice(12, 23);
    device.networking();
    device.plugAndPlay();
    // device.getID(); // 중복되는 함수 -> 오류
    cout << device.USBDevice::getID() << endl;
    cout << device.NetworkDevice::getID() << endl;
    return 0;
}
