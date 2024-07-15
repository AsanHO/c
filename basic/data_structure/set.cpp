// 중복 제거 하고 싶으면 그냥 왠만하면 unique()쓰자
// 멀티 셋은 써볼만 할지도??

#include <bits/stdc++.h>

using namespace std;

multiset<int> s;
int main(){
    for (int i =5; i > 0;i --){
        s.insert(i);
        s.insert(i);
    }
    for (int it : s) cout << it <<" ";
    return 0;
}