/*
3.association.cpp
*/
#include <iostream>
#include <string>
#include <vector>

#include "Lecture.h"

int main() {
    using namespace std;

    Student *student1 = new Student("이은호", 0);
    Student *student2 = new Student("신소이", 1);
    Student *student3 = new Student("정근영", 2);

    Teacher *teacher1 = new Teacher("황석형");
    Teacher *teacher2 = new Teacher("이영한");

    Lecture lecture1 = Lecture("Introduction to Computer Programming");
    lecture1.assignTeacher(teacher1);
    lecture1.registerStudent(student1);
    lecture1.registerStudent(student2);
    lecture1.registerStudent(student3);

    Lecture lecture2 = Lecture("Computational Thinking");
    lecture2.assignTeacher(teacher2);
    lecture2.registerStudent(student1);

    /*
    composition 관계에서는 lec2수업을 해도 lec1의 같은 학생의 지능이 올라가지 않음
    */

    // test
    {
        cout << lecture1 << endl;
        cout << lecture2 << endl;

        lecture2.study();

        cout << lecture1 << endl;
        cout << lecture2 << endl;
    }

    delete student1;
    delete student2;
    delete student3;
    delete teacher1;
    delete teacher2;
}