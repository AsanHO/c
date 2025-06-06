/*
association : 제휴관계
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Doctor;  // forward declaration; 제휴관계의 경우 전방선언을 해주는 경우가 많다. 이외에도 밑의 함수 분리와 같은 문제가 발생할 수 있어 구현하기 까다로운 경우가 많다.
class Patient {
   private:
    string m_name;
    vector<Doctor*> m_doctors;

   public:
    Patient(string name_in) : m_name(name_in) {}

    void addDoctor(Doctor* new_doc) { m_doctors.push_back(new_doc); }

    void meetDoctors();
    friend class Doctor;
};
class Doctor {
   private:
    string m_name;
    vector<Patient*> m_patients;

   public:
    Doctor(string name_in) : m_name(name_in) {}
    void addPatient(Patient* new_pat) { m_patients.push_back(new_pat); }
    void meetPatients() {
        for (auto& pat : m_patients) {
            cout << "Meet Patients : " << pat->m_name << endl;
        }
    }
    friend class Patient;
};

void Patient::meetDoctors() {
    {
        for (auto& doc : m_doctors) {
            cout << "Meet doctor : " << doc->m_name << endl;
        }
    }
}
int main() {
    Patient* p1 = new Patient("uno");
    Patient* p2 = new Patient("soi");
    Patient* p3 = new Patient("gun");

    Doctor* d1 = new Doctor("guk");
    Doctor* d2 = new Doctor("jak");

    p1->addDoctor(d1);
    d1->addPatient(p1);

    p2->addDoctor(d2);
    d2->addPatient(p2);

    p2->addDoctor(d1);
    d1->addPatient(p2);

    p1->meetDoctors();
    d1->meetPatients();
    delete p1;
    delete p2;
    delete p3;
    delete d1;
    delete d2;
}