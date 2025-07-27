/*
3.exception_class.cpp
*/

#include <iostream>

using namespace std;

class Exception {
   public:
    void report() { cerr << "Exception" << endl; }
};
class ArrayException : public Exception {
   public:
    void report() { cerr << "Array Exception" << endl; }
};
class MyArray {
   private:
    int m_data[5];

   public:
    int& operator[](const int& index) {
        // if (index < 0 || index > 5) throw -1;
        // if (index < 0 || index > 5) throw Exception();
        if (index < 0 || index > 5) throw ArrayException();
        return m_data[index];
    }
};

void func() {
    MyArray arr;
    try {
        arr[100];
    } catch (const int& x) {
        cerr << "exception" << x << endl;

    } catch (ArrayException& e) {
        e.report();
        // 만약 부모클래스를 먼저 catch하게 되면 ArrayException catch가 안됨.
        // !!따라서 부모 클래스 위에 예외처리문을 작성해야함
        throw e;
    } catch (Exception& e) {
        e.report();
        // ArrayException 가 없어도 대체 할 수 있지만 개체 잘림 현상이 나타남
    }
}
int main() {
    try {
        func();
    } catch (ArrayException& e) {
        e.report();
    }
    return 0;
}