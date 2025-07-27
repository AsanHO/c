/*
4.std::exception.cpp
이미 다양한 경우의 예외에 대해서 각각 이미 구현이 되어 있다
-> 구현할 필요가 없음 ㅎㅎ
*/

#include <exception>
#include <iostream>
#include <string>
class CustomException : public std::exception {
   public:
    // noexcept : 이 함수는 예외를 던지지 않는다.
    const char* what() const noexcept override { return "Custom Exception"; }
};
int main() {
    try {
        // std::string s;
        // s.resize(-1);

        // throw std::runtime_error("bad thing happened");

        throw CustomException();
    } catch (std::length_error& e) {
        std::cerr << "length_error" << std::endl;
        std::cerr << typeid(e).name() << std::endl;
        std::cerr << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cerr << typeid(e).name() << std::endl;
        std::cerr << e.what() << std::endl;
    }
    return 0;
}