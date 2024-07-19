#include <bits/stdc++.h>

using namespace std;


int gcd(int a,int b){
    if (a==0){
        return b;
    }
    return gcd(b%a,a);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(int argc, char const *argv[]){
    int a = 5;
    int b = 100;
    cout << gcd(a,b) << '\n';
    cout << lcm(a,b) << '\n';
    return 0;
}
