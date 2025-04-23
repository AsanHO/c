/*
alias 가명 : 가짜 이름 내지 별명
용어 자체는 리눅스에서 많이 씀
컴파일러 입장에선 변하는게 없으므로 클린코드를 위한것
*/

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    typedef double distance_t;
    double d1;
    distance_t d2;
    distance_t d3;
    // d2와 d3가 나중에 float으로 바꿔줘야 한다면 유지보수에 용이하다.

    typedef vector<pair<string, int>> pairList_t;
    // using  pairList_t = vector<pair<string, int>>;
    // 위에 코드도 동일, 그러나 내부적 원리는 다르다.
    pairList_t pairlist1;
    pairList_t pairlist2;
}