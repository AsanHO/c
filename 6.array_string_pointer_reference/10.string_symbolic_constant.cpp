#include <iostream>
// 문자열 기호적 상수 : 컴파일 시, 같은 값이 있는 코드들은 같은 주소를 가리킨다.
// 통념과는 다르게 작동하기 때문에 주의해야한다.
// 물론 std를 사용하면 그렇게 주의할 필요는 없겠다.
/*
컴파일러가 "이건 값이 똑같은데, 굳이 메모리 두 번 쓸 이유 있냐?"
→ 라고 판단해서,
한 번만 메모리에 올리고 같은 주소를 여러 곳에서 참조하게 만드는 거다.
*/
using namespace std;

// 리턴타입으로도 사용 가능
const char *getName() { return "Jack Smith"; }
int main() {
    // char name [] = "Jack Smith";
    // char *name = "Jack Smith"; 작동 안됨
    const char *name = "Jack Smith";    // 기호적 상수
    const char *name2 = "Jack Smith";   // 기호적 상수
    const char *name3 = "Jack Smith3";  // 기호적 상수

    cout << (uintptr_t)name << endl;
    cout << (uintptr_t)name2 << endl;
    cout << (uintptr_t)getName() << endl;
    cout << (uintptr_t)name3 << endl;
    // result
    // 참고로 문자열 포인터를 출력한다고 해도 주소값이 출력되지는 않는다. 때문에
    // 강제 형변환을 해줘야 한다. 4332093304 4332093304 4332093304 4332093315
    // name1과 name2의 getName()주소가 같다. 3개의 같은 값을 가지게 된 변수는
    // 컴파일 시, 같은 주소를 가리킨다.
    return 0;
}