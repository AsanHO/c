#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[10][10];
int main() {
    fill(&a[0], &a[10], 100); // a[10]은 포함하지 않음
    for (int i = 0; i < 12; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    fill(&b[0][0], &b[9][10], 2);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            cout << b[i][j] << " ";
        }
        cout << i <<'\n';
    }
    return 0;
}