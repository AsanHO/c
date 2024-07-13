// c++이 많은 라이브러리를 지원하는데도 불구하고 split을 지원하지는 않는다.
/*
split(input,delimeter)이라는 함수를 만들어보자
완전탐색으로 " "가 있는 인덱스를 찾고 해당인덱스를 분기점으로 배열을 슬라이싱한다.
 */
#include <bits/stdc++.h>
using namespace std;

/*
컴파일 이후 유저 입력으로
Array로 선언을 하게 되면 길이를 측정할 수 없기에
컴파일에러가 작동한다.
런타임 이후 리스트의 크기가 결정된다면, vector를 사용해야한다.

일부 컴파일러는 이 에러를 감지해주지만 권장사항을 따르자
 */
vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    //npos string 변수의 상태로 해당 문자열이 없는 상태를 의미한다. find메소드는 정수 혹은 npos를 반환하는 것이다.
    while ((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

//성능개선 버전
vector<string> splitV2(const string& input, string delimiter){
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos){
        result.push_back(input.substr(start,end - start));
        start = end + delimiter.size();
        end = input.find(delimiter,start);
    }
    result.push_back(input.substr(start));
    return result;

}

int main() {
    string s = "2024년 6월 16일 일요일 이은호는 커피한잔이라는 카페에서 c++을 공부하고 있다.";
    string d = " ";
    vector<string> a = splitV2(s,d);
    for(string sliced : a) {
        cout << sliced << "\n";
    }
    return 0;
}