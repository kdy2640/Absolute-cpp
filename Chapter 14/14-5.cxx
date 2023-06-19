
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;


namespace Hospital
{
    // Person 클래스 정의
    class Person {
    public:
        Person() :name("") {}
        Person(string _name) : name(_name) {}
        Person(const Person& _P1) { name = _P1.getName(); }

        string getName() const { return name; }
        void setName(string _name) { name = _name; }

        Person& operator=(const Person& _P1) { name = _P1.getName(); return *this; }

    private:
        string name;
    };

    // Doctor 클래스 정의
    class Doctor : public Person {
    public:
        Doctor() : Person(), speciality("") {}
        Doctor(string _name, string _sp) : Person(_name), speciality(_sp) {}
        Doctor(const Doctor& _D1) { operator=(_D1); speciality = _D1.getSpeciality(); }

        string getSpeciality() const { return speciality; }
        void setSpeciality(string _sp) { speciality = _sp; }

        Doctor& operator=(const Doctor& _D1) { Person::operator=(_D1); speciality = _D1.getSpeciality(); return *this; }

    private:
        string speciality;
    };

    // Patient 클래스 정의
    class Patient : public Person {
    public:
        Patient() : Person(), primaryPhysician() {}
        Patient(string _name, Doctor _D1) : Person(_name), primaryPhysician(_D1) {}
        Patient(const Patient& _P1) { operator=(_P1); primaryPhysician = _P1.getDoctor(); }
        Doctor getDoctor() const { return primaryPhysician; }
        void setDoctor(const Doctor& _P1) { primaryPhysician = _P1; }
        string getDoctorName() const { return primaryPhysician.getName(); }
        string getDoctorSpeciality() const { return primaryPhysician.getSpeciality(); }


        Patient& operator=(const Patient& _P1) { Person::operator=(_P1); primaryPhysician = _P1.getDoctor(); return *this; }

    private:
        Doctor primaryPhysician;
    };

    // Billing 클래스 정의
    class Billing {
    public:
        Billing() : patient(), doctor(), aDue(0.0) {}
        Billing(Patient _patient, Doctor _doctor, double _aDue) : patient(_patient), doctor(_doctor), aDue(_aDue) {}
        Billing(const Billing& _B1) : doctor(_B1.getDoctor()), patient(_B1.getPatient()), aDue(_B1.getAmountDue()) {}

        Patient getPatient() const { return patient; }
        Doctor getDoctor() const { return doctor; }
        double getAmountDue() const { return aDue; }
        void setAmountDue(double _aDue) { aDue = _aDue; }

        Billing& operator=(const Billing& _B1) { doctor = _B1.getDoctor(); patient = _B1.getPatient(); aDue = _B1.getAmountDue(); return *this; }
        void printCheck()
        {
            cout << "\n__________________________________________________\n";
            cout << "Doctor's name is " << doctor.getName() << endl;
            cout << "Doctor's Speciality is " << doctor.getSpeciality() << endl;
            cout << "Patient's name is " << patient.getName() << endl;
            cout << "Patient's Doctor is " << patient.getDoctorName() << endl;
            cout << "Patient's Doctor's Speciality is " << patient.getDoctorSpeciality() << endl;
            cout << "AmountDue is " << aDue << endl;
            cout << "_________________________________________________\n";
        }

    private:
        Patient patient;
        Doctor doctor;
        double aDue;
    };

} // namespace Hospital