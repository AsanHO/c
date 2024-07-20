#include <bits/stdc++.h>

using namespace std;

vector<int> mans;
vector<int> indexes;

void print(vector<int> v){
    for (auto i : v){
        cout << i << '\n';
    }
}

void combi(int start,vector<int> v){
    if (v.size() == 7){
        int sum = 0;
        for (int i : v){
            cout << i;
            sum += mans[i];
        }
        if (sum == 100){
            for (int i : v){
            // cout << mans[i];
            }
        }
        cout << '\n';
        return;
    }
    for (int i = start + 1; i < 9; i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(int argc, char const *argv[]){
    
    for (int i = 0; i<9;i++){
        int man;
        cin >> man;
        mans.push_back(man);
    }
    sort(mans.begin(),mans.end());
    // print(mans);
    combi(-1,indexes);
    return 0;
}
