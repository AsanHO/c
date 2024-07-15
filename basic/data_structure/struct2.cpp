#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}
// sort 함수는 <가 관례이다. 생각하지말고 a < b , b < a  모두 첫번째 인자가 우선순위가 높은것이라 보면 된다.

struct Point{
    int y, x;
    Point(int y, int x) : y(y), x(x){}
    Point(){y = -1; x = -1; }
    bool operator < (const Point & a) const{
    if(x == a.x) return y < a.y;
    return x < a.x;
    }
};
int main(){
    string a[3] = {"111","222","33"};
    sort(a,a+3,compare);
    for(auto w : a) cout << w << " "; 

    Point point = Point(1,2);
    return 0;
}

