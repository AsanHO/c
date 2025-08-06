/*
3.multi_thread_basic.cpp
CS에서 배운 프로그래밍 기술들은 대부분 단일 코어 CPU로 가정을 하고
순차적으로 해결하는 것을 기본적으로 여긴다.
그러나 최근의 컴퓨팅환경은 대부분 멀티코어 CPU위에서 작동하고 있다.
현대 프로그래머라면 당연히 이런 환경에 대응 할 수 있어야한다.

Distributed Computing 분산처리 : 여러대의 PC가 네트워크를 통해 하나의 임무를 수행
-> 메모리는 공유할 수 없다.

멀티스레딩 : 여러대의 스레드가 한 메모리를 공유
-> 양날의 검으로 매우 빨리지지만 매우 위험하기도 하다.
-> CPU에서 자동으로 해주는 게 아니라 프로그래머가 직접 멀티스레딩을 하도록 프로그램을 작성해야만 한다.

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

int main() { return 0; }
