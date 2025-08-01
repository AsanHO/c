/*
6.file_IO.cpp
실무에서는 콘솔 입출력 위주가 아닌 파일 위주이다.
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // {
    //     ofstream ofs("my_first_file.dat");
    //     // 파일이 생성된다!
    //     if (!ofs) {
    //         cerr << "Couldn't open file" << endl;
    //         exit(1);
    //     }
    //     ofs << "Line 1" << endl;
    //     ofs << "Line 2" << endl;
    //     // 텍스트가 작성된다!
    // }
    // {
    //     ifstream ifs("my_first_file.dat");
    //     if (!ifs) {
    //         cerr << "Couldn't open file" << endl;
    //         exit(1);
    //     }

    //     while (ifs) {
    //         std::string str;
    //         getline(ifs, str);
    //         cout << str << endl;
    //     }
    // }

    // 위의 코드는 ASCII -> 느리다. -> 이진코드 작성

    {
        ofstream ofs("my_first_file.dat");
        // 파일이 생성된다!
        if (!ofs) {
            cerr << "Couldn't open file" << endl;
            exit(1);
        }

        const unsigned num_data = 10;
        ofs.write((char*)&num_data, sizeof(num_data));

        for (int i = 0; i < num_data; i++) {
            ofs.write((char*)&i, sizeof(i));
        }
    }
    {
        ifstream ifs("my_first_file.dat");
        if (!ifs) {
            cerr << "Couldn't open file" << endl;
            exit(1);
        }

        unsigned num_data = 0;
        ifs.read((char*)&num_data, sizeof(num_data));

        for (unsigned i = 0; i < num_data; i++) {
            int num;
            ifs.read((char*)&num, sizeof(num));
            cout << num << endl;
        }
    }
    // 다만 binary file은 시각화가 어려운점이 있다.
}