/*
12-3.override_final_covarint.cpp
covariant : 공변반환값

부모클래스의 경우 다른 파일에 있는 경우가 잦을텐데 그러한 함수들을 정확하게 외우고, 기록하는 것은 쉽지 않다.

*/
#include <iostream>
using namespace std;

class A {
   public:
    virtual void print(const int& x) { cout << "A" << endl; }
};
class B : public A {
   public:
    // void print(const double& x) override{ cout << "B" << endl; }
    void print(const int& x) override { cout << "B" << endl; }
    // 오버라이드 키워드를 작성하면 오버라이딩과 관련하여 컴파일러가 오류가 날 수 있는 여지가 있는 부분을 알려준다.
    // -> 실수가 날 확률을 줄여준다.
    virtual void print2(const int& x) final { cout << "B" << endl; }
    // final 키워드를 사용하면 해당 함수를 오버라이드 할 수 없게 된다.
};

class C : public B {
   public:
    // void print(const double& x) override { cout << "C" << endl; }
    // 오버라이드 키워드를 작성하면 오버라이딩과 관련하여 컴파일러가 오류가 날 수 있는 여지가 있는 부분을 알려준다.
    // -> 실수가 날 확률을 줄여준다.
    void print(const int& x) override { cout << "C" << endl; }
    // final 키워드를 사용하면 해당 함수를 오버라이드 할 수 없게 된다.
    // 따라서 C클래스에서 B클래스의 print2()를 오버라이드 할 수 없다.
};

class T {
   public:
    void print() { cout << "T" << endl; }
    virtual T* getThis() {
        cout << "T::getThis()" << endl;
        return this;
    }
};

class T2 : public T {
   public:
    void print() { cout << "T2" << endl; }
    // covariant return type
    // 부모 클래스의 함수가 반환하는 타입을 자식 클래스에서 오버라이드 할 때
    // 자식 클래스의 타입으로 변경할 수 있다.
    virtual T2* getThis() {
        cout << "T2::getThis()" << endl;
        return this;
    }
};
int main() {
    A a;
    B b;
    A& ref = b;
    ref.print(1);  // B::print() 호출, A::print()가 아닌 B::print()가 호출된다.
    ref.print(1.0);

    // covariant return type
    T t;
    T2 t2;

    T& ref2 = t2;
    t2.getThis()->print();
    ref2.getThis()->print();

    cout << typeid(t2.getThis()).name() << endl;
    cout << typeid(ref2.getThis()).name() << endl;
    return 0;
}