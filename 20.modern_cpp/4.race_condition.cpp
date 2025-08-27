/*
4.race_condition.cpp
- 멀티 스레딩은 여러개의 스레드들이 하나의 메모리 공간을 함께 사용하기때문에
- 다른 병렬처리기법보다 구현하기 편리하다.
- 허나 이 장점은 단점이 될 수도 있으며 이를 레이스 컨디션이라고 한다.
- 이를 atomic과 mtx, scoped_lock으로 해결하는 방법을 알아본다.
- !! 레이스컨디션은 디버깅하기 정말 어렵다!!(눈치채기가 어렵다.)
*/

#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
mutex mtx;

int main() {
    int shared_memory(0);
    // atomic<int> shared_memory(0);
    auto count_func = [&]() {
        for (int i = 0; i < 1000; i++) {
            this_thread::sleep_for(chrono::milliseconds(1));
            // mtx.lock();
            // std::lock_guard lock(mtx);  // 락가드 권장
            std::scoped_lock lock(mtx);  // c++17이후 락가드 권장
            shared_memory++;
            // mtx.unlock();
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    t1.join();
    t2.join();

    cout << "After" << endl;
    cout << shared_memory << endl;
    // 기댓값은 2000이지만 1989등이 출력됨
    /*
    동시에 값을 호출한경우,
    10 t1 => 11
    10 t2 => 11
    연산은 두번수행했으나, 한번만 실행한 꼴이 된다.
    Operation
    1. 값을 읽는다.
    2. 값을 바꾼다.
    3. 값을 적용한다.
    이를 atomic을 통해 묶어버린다.
    -> 단점 : 당연히 조금은 느려진다. (함부로 쓰지는 말 것)
    */
    return 0;
}
