#pragma once

#include "Person.h"

class Teacher : public Person {
   private:
    // Todo: more members like home address, salary, age, evaluation, etc.

   public:
    Teacher(const std::string& name_in = "No Name") : Person(name_in) {}

    friend std::ostream& operator<<(std::ostream& out, const Teacher& teacher) {
        out << teacher.getName();
        return out;
    }
};