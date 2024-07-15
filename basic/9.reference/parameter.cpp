#include <bits/stdc++.h>

using namespace std;

void addValue(int a,int b){
    a += 1;
    b += 1;
}

void addReference(int &a,int b){
    a += 1;
    b += 1;
}


int main(){
    int a = 1;
    int b = 2;
    addValue(a,b);
    cout << "a : " << a << "\n";
    cout << "b : " << b << "\n";
    addReference(a,b);
    cout << "a : " << a << "\n";
    cout << "b : " << b << "\n";
}

/*
언제 참조를 써야하노?
인스턴스화가 가능한 타입(String,struct,class.int[])
왜? 복사에 의한 메모리 비용이 많이 들기 때문으로
*/