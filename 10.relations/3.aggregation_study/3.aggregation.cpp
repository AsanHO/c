/*
3.association.cpp
*/
#include <iostream>
#include <string>
#include <vector>

#include "Lecture.h"

int main() {
    using namespace std;
    Lecture lecture1 = Lecture("Introduction to Computer Programming");
    lecture1.assignTeacher(Teacher("이영한"));
    lecture1.registerStudent(Student("이은호", 0));
    lecture1.registerStudent(Student("신소이", 1));
    lecture1.registerStudent(Student("정근영", 2));

    Lecture lecture2 = Lecture("Computational Thinking");
    lecture2.assignTeacher(Teacher("황석형"));
    lecture2.registerStudent(Student("이은호", 0));

    // TODO : implement Aggregation Relationship
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
}