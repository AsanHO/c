#include <bits/stdc++.h>

using namespace std;

int n = 2;
int r = 1;
int arr[] = {1, 2};

vector<int> v;

void print(vector<int> v){
    for (auto i:v){
        cout << i ;
    }
    cout << '\n';
}

void combi(int start, vector<int> v){
    // 3개의 구슬이 뽑아지면
    if(v.size() == r){
        print(v);
        return;
    }
    for(int i=start+1; i < n; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}
int main(){
    combi(-1,v);
}
