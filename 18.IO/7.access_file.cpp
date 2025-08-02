/*
7.access_file_to_specific_location.cpp
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    const string filename = "my_file.txt";
    {
        ofstream ofs(filename);

        for (char i = 'a'; i <= 'z'; i++) {
            // You can write to the file like this:
            ofs << i;
        }
        ofs << endl;
    }
    {
        ifstream ifs("my_file.txt");

        ifs.seekg(5);  // 5바이트 다음부터 읽는 메소드
                       // ifs.seekg(5,ios::beg); 시작위치로부터 5바이트
        cout << (char)ifs.get() << endl;

        ifs.seekg(5, ios::cur);  // 현재 커서로부터 5바이트 다음부터 읽는 메소드
        cout << (char)ifs.get() << endl;
    }
}