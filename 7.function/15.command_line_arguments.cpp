/*
15.command_line_arguments
main 안에 매개변수를 넣어보자
*/
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    // argc는 명령행 인수의 개수
    // argv는 명령행 인수의 배열
    // argv[0]은 프로그램의 이름
    // argv[1]부터 argv[argc-1]까지는 명령행 인수
    // argv는 char* 형식의 배열이다.
    // 즉, char* argv[]와 char** argv는
    // 같은 의미이다.
    // exe파일에 전달할수 있는 방법
    // cin을 사용하지 않고, 입력을 받을 수 있다.
    cout << "argc: " << argc << endl;
    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;

    // cd "/Users/eunho/Desktop/c/7.function/" && g++ -std=c++17 15.command_line_arguments.cpp -o 15.command_line_arguments && "/Users/eunho/Desktop/c/7.function/"15.command_line_arguments 100
    // 같이 15.command_line_arguments 100
    // argv[0]은 프로그램의 이름이다.
    // argv[1]은 첫 번째 인수가 출력된다.
}