/*
문자열을 정수로 변환하는 법.
해당 문자열을 아스키코드로 검사한 후 맞는게 있다면 정수로 바꾸는것이라
가설
atoi ASCII to integer
정수가 아니면 0을 반환함. 이는 문제가 생길여지가 있으므로
stoi의 경우 에러를 리턴한다.
*/
#include <bits/stdc++.h>

using namespace std;
int main(){
    string s = "1234";
    string s2 = "amumu";
    cout << atoi(s.c_str()) << '\n';
    cout << atoi(s2.c_str()) << '\n';
    cout << stoi(s.c_str()) << '\n';
    // 컴파일에러
    // cout << atoi(s2.c_str()) << '\n';
    return 0;
}