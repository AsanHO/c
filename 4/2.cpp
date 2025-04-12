/*
전역변수는 안전하지 않기 때문에 주의해서 사용해야한다.
*/
#include <bits/stdc++.h>

using namespace std;

/*
Static Duration Variable : 디버깅 | 테스트 시 사용 릴리즈코드에는 많이 없음
정적 기간 변수
1. 전역변수를 사용해도 되지않을까?
2. static 의미 : 메모리가 고정되어 있다. 동적할당에서 한번더 배운다.
3. 유사한 개념 : 싱글턴
4. 전역변수를 피하기 가장 좋은 대안 -> 객체지향 프로그래밍
5. 마스터가 되면 오히려 전역변수를 잘 사용할 수 있다.
6. 전역변수는 디버깅 추적이 어렵다. 때문에 g_value 처럼 변수에 명명을 해주는 것도 좋다.
*/

// 밑의 변수는 external global variable로써 외부 파일에서도 접근이 가능하다.
int g_value = 123;

// 밑의 변수는 internal global variable로써 외부 파일에서도 접근이 불가능하다.
static int static_value = 123;
// 즉 스태틱은 현재 선언된 스코프 안에서만 유효하다.(물론 포인터를 쓴다면 이야기가 달라지겠지만)

void doSomething() {
    static int a = 1;  // 정의와 동시에 고정 : 선언과 할당 무조건 동시에 해야함
    a += 1;
    cout << a << endl;
    // non static 이라면 메모리반납
}
int main() {
    cout << value << endl;

    int value = 1;

    cout << value << endl;
    cout << ::value << endl;

    doSomething();
    doSomething();
}