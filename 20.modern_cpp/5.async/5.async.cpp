/*
4.async
*/
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main() {
    // multi-threading
    {
        int result;
        std::thread t([&] { result = 1 + 2; });
        t.join();
        cout << result << endl;
    }
    // task-based parallelism
    {
        auto fut = std::async([] { return 1 + 2; });
        // 일반적으로 스레드보다는 asnyc를 선호한다.
        // 리턴해줄때까지 작업대기
        cout << fut.get() << endl;
    }
    // future & promise
    {
        std::promise<int> prom;
        auto fut = prom.get_future();
        auto t = std::thread([](std::promise<int>&& prom) { prom.set_value(1 + 2); }, std::move(prom));
        cout << fut.get() << endl;
        t.join();
    }
    {
        auto f1 = std::async([] {
            cout << "async1 start" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "async1 end" << endl;
        });
        auto f2 = std::async([] {
            cout << "async2 start" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "async2 end" << endl;
        });
        cout << "main func" << endl;
    }
    return 0;
}