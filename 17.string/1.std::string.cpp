/*
1.std.cpp
*/

#include <cstddef>
#include <iostream>
#include <locale>
#include <string>

int main(void) {
    // c-style string example  귀 찮 다.
    // {
    //     char *strHello = new char[7];
    //     strcpy(strHello, sizeof(char) * 7, "hello!");
    // }
    {
        std::string string;
        std::wstring wstring;  // wide 국제어 사용시 사용

        wchar_t wc;
    }
    {
        // std::string my_string = "hell yeah";
        const char* my_string = "hell yeah";

        std::string my_string2 = my_string;
        std::cout << my_string2 << std::endl;

        std::string my_string3(my_string, 3);
        std::cout << my_string3 << std::endl;

        std::string my_string4(my_string, 3, 5);
        std::cout << my_string4 << std::endl;
    }
    return 0;
}