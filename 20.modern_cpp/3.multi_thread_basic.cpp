/*
3.multi_thread_basic.cpp
CS에서 배운 프로그래밍 기술들은 대부분 단일 코어 CPU로 가정을 하고
순차적으로 해결하는 것을 기본적으로 여긴다.
그러나 최근의 컴퓨팅환경은 대부분 멀티코어 CPU위에서 작동하고 있다.
현대 프로그래머라면 당연히 이런 환경에 대응 할 수 있어야한다.

Distributed Computing 분산처리 : 여러대의 PC가 네트워크를 통해 하나의 임무를
수행
-> 메모리는 공유할 수 없다.

멀티스레딩 : 여러대의 스레드가 한 메모리를 공유
-> 양날의 검으로 매우 빨리지지만 매우 위험하기도 하다.
-> CPU에서 자동으로 해주는 게 아니라 프로그래머가 직접 멀티스레딩을 하도록
프로그램을 작성해야만 한다.

메인스레드는 서브스레드가 작업이 언제 끝내는지 알 수 없다.
(오는데는 순서가 있어도 가는덴 순서가 없다.)
*/
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;
mutex mtx;  // mutual exclusion
int main() {
    const int process_amount = std::thread::hardware_concurrency();
    cout << process_amount << endl;

    cout << std::this_thread::get_id()
         << endl;  // main함수가 실행이 되고 있는 스레드의 주소
    // {
    //     std::thread t1 = std::thread([]() {
    //         cout << std::this_thread::get_id() << endl;
    //         while (true) {
    //         }
    //     });

    //     std::thread t2 = std::thread([]() {
    //         cout << std::this_thread::get_id() << endl;
    //         while (true) {
    //         }
    //     });

    //     std::thread t3 = std::thread([]() {
    //         cout << std::this_thread::get_id() << endl;
    //         while (true) {
    //         }
    //     });

    //     std::thread t4 = std::thread([]() {
    //         cout << std::this_thread::get_id() << endl;
    //         while (true) {
    //         }
    //     });
    //     t1.join();  // t1이 끝날때까지 main 스레드의 주소는 await
    //     t2.join();
    //     t3.join();
    //     t4.join();
    // }

    // {
    //     vector<std::thread> my_threads;
    //     my_threads.resize(process_amount);

    //     for (auto& t : my_threads) {
    //         t = std::thread([]() {
    //             cout << std::this_thread::get_id() << endl;
    //             while (true) {
    //             }
    //         });
    //     }
    //     for (auto& t : my_threads) t.join();
    // }

    {
        auto work_func = [](const string& name) {
            for (int i = 0; i < 5; ++i) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                mtx.lock();
                cout << name << " " << std::this_thread::get_id()
                     << " is working " << i << endl;
                mtx.unlock();
            }
        };
        std::thread t1 = std::thread(work_func, "nakeum");
        std::thread t2 = std::thread(work_func, "uno");
        t1.join();
        t2.join();
    }
    return 0;
}
