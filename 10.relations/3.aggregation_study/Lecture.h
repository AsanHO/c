#pragma once

#include <vector>

#include "Student.h"
#include "Teacher.h"

class Lecture {
   private:
    std::string m_name;
    Teacher teacher;
    std::vector<Student> students;

    // Teacher *teacher;
    // std::vector<Strudent*> students;

   public:
    Lecture(const std::string& name_in) : m_name(name_in) {}
    ~Lecture() {
        // DO NOT DELETE TEACHER
        // DO NOT DELETE STUDENTS
    }
    void assignTeacher(const Teacher& teacher_input) { teacher = teacher_input; }

    void registerStudent(const Student& student_input) { students.push_back(student_input); }

    void study() {
        std::cout << m_name << " Study " << std::endl << std::endl;

        for (auto& student : students) {  // auto 는 작동 안함 레퍼런스가 필요하다.
            student.setIntel(student.getIntel() + 1);
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Lecture& lecture) {
        out << "Lecture name : " << lecture.m_name << std ::endl;
        out << lecture.teacher << std::endl;
        for (auto student : lecture.students) {
            out << student << std::endl;
        }
        return out;
    }
};