/*
7.pure_abstract_interface.cpp

설계라는 관점에서 기본 클래스를 만들 때 자식클래스에게 제약을 주기 위한

순수 가상 함수 - 바디가 없는 함수(자식 클래스에서 반드시 오버라이드해야함)
추상 기본 클래스 - 순수 가상 함수가 포함된 클래스
인터페이스 클래스 - 순수 가상 함수로만 이루어진 클래스
를 학습한다.

*/

#include <iostream>
using namespace std;

class Animal {
   protected:
    string m_name;

   public:
    Animal(const string& name) : m_name(name) {}

   public:
    string getName() const { return m_name; }
    virtual void speak() const = 0;  // 순수 가상 함수 pure virtual function
};

class Dog : public Animal {
   public:
    Dog(const string& name) : Animal(name) {}

   public:
    void speak() const { cout << "Woof! My name is " << getName() << endl; }
};

class Cat : public Animal {
   public:
    Cat(const string& name) : Animal(name) {}

   public:
    void speak() const { cout << "Meow! My name is " << getName() << endl; }
};

class Cow : public Animal {
   public:
    Cow(const string& name) : Animal(name) {}

    //    public:
    //     void speak() const { cout << "Moo! My name is " << getName() << endl; }
};

// 인터페이스 클래스 예시
class IErrorLog {  // I를 접두사로 붙여 인터페이스 클래스임을 나타내는 관행
   public:
    virtual bool reportError(const char* errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog {
   public:
    bool reportError(const char* errorMessage) override {
        cout << "File Error Log: " << errorMessage << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog {
   public:
    bool reportError(const char* errorMessage) override {
        cout << "Console Error Log: " << errorMessage << endl;
        return true;
    }
};

void func(IErrorLog& log) { log.reportError("Runtime error!"); }

int main() {
    // Animal animal("Generic Animal");  // 오류: Animal은 추상 클래스이므로 인스턴스화할 수 없음
    Dog dog("Buddy");
    dog.speak();

    Cat cat("Whiskers");
    cat.speak();

    // Cow cow("Bessie");
    // cow.speak();
    // 오류: Cow는 speak() 순수가상함수를 오버라이드하지 않았으므로

    FileErrorLog fileLog;
    ConsoleErrorLog consoleLog;

    func(fileLog);     // FileErrorLog를 통해 오류 메시지를 기록
    func(consoleLog);  // ConsoleErrorLog를 통해 오류 메시지를 기록
    return 0;
}