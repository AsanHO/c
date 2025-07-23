#include <iostream>
/*
다형성(Polymorphism)
자식클래스의 객체를 부모클래스의 포인터나 참조로 다룰 수 있는 기능
*/
using namespace std;

class Animal {
   private:
    string m_name;

   public:
    Animal(const string& name) : m_name(name) {}

   public:
    string getName() const { return m_name; }
    virtual void speak() const { cout << m_name << "???" << endl; }
    /*
    🚨 제일 중요한 구문, virtual구문으로 인해 다형성이 가능해진다.
    virtual 키워드를 사용하면, 이 함수는 가상 함수가 되어,
    해당 클래스를 상속받은 클래스에서 이 함수를 재정의(override)
    할 수 있게 된다. 이로 인해, Animal 클래스의 포인터나 참조를
    사용하여, 실제 객체의 타입에 따라 올바른 speak() 함수가 호출된다
    (즉, Cat 클래스의 speak() 또는 Dog 클래스의 speak()가 호출됨)
    */
};

class Cat : public Animal {
   public:
    Cat(const string& name) : Animal(name) {}

   public:
    void speak() const { cout << getName() << " meow!" << endl; }
};

class Dog : public Animal {
   public:
    Dog(const string& name) : Animal(name) {}

   public:
    void speak() const { cout << getName() << " woof!" << endl; }
};

int main() {
    Animal animal("Generic Animal");
    Cat cat("Whiskers");
    Dog dog("Buddy");
    animal.speak();  // Generic Animal???
    cat.speak();     // Whiskers meow!
    dog.speak();     // Buddy woof!

    Animal* animalPtr = &cat;   // Upcasting
    Animal* animalPtr2 = &dog;  // Upcasting
    animalPtr->speak();         // Whiskers meow! (Cat's speak method called)
    animalPtr2->speak();        // Buddy woof! (Dog's speak method called)

    /*
    언제 쓰나요??에 대한 예시
    */
    Cat cats[] = {Cat("Kitty"), Cat("Tom"), Cat("Felix"), Cat("Garfield"), Cat("Sylvester")};
    Dog dogs[] = {Dog("Rex"), Dog("Max"), Dog("Buddy"), Dog("Charlie"), Dog("Rocky")};

    for (const auto& c : cats) {
        c.speak();
    }
    for (const auto& d : dogs) {
        d.speak();
    }

    Animal* animals[] = {&cats[0], &dogs[0], &cats[1], &dogs[1], &cats[2], &dogs[2], &cats[3], &dogs[3], &cats[4], &dogs[4]};
    // 실무에서는 위처럼 포인터 쓸필요없이 벡터나 어레이를 사용하면 되겠다.

    for (const auto& animal : animals) {
        animal->speak();  // Calls the appropriate speak method based on the actual object type
    }
}