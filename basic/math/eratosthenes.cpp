#include <bits/stdc++.h>

using namespace std;


bool isdecimal(int n){
    if ((n <= 1) || (n % 2==0)){
        return false;
    }
    if (n == 2){
        return true;
    }
    for (int i =3; i * i <=n; i++){
        if (n % i == 0) return false;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    /* code */
    for(int i =1; i <=999; i ++){
        if(isdecimal(i)) {
            cout << i << '\n';
        }
    }
    return 0;
}
