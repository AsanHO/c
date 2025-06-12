/*
앞 파일에서 상속이 어떤식으로 이루어지는지 빠르게 훑어보았다.
때문에 이 파일에서는 실제사례를 통해 좀 더 자세하게 알아보겠다.
*/
/*
1. Student와 Teacher의 공통된 속성인 m_name을 통해 Person이라는 클래스로
일반화한다.
(객체지향에 익숙해진다면 Person을 먼저 만들게 된다.)
*/

#include "Student.h"
#include "Teacher.h"

int main() {
    Student std("이은호");
    Teacher teacher1("이영한");
    std.setName("정근영");
    std::cout << std << std::endl;
    std::cout << teacher1 << std::endl;

    return 0;
}