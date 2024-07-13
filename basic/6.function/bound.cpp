#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
vector<int> a =  {1, 2, 3, 3, 3, 4};
cout << &*lower_bound(a.begin(), a.end(), 3)<< "\n";
cout << &*a.begin()<< "\n";
cout << &*(a.begin() + 1)<< "\n";
return 0;
}