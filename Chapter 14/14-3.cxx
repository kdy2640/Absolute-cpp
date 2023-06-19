
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;



namespace SavitchEmployees
{
    class Employee
    {
    public:
        Employee();
        Employee(const string& theName, const string& theSsn);
        string getName() const;
        string getSsn() const;
        double getNetPay() const;
        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(double newNetPay);
        void printCheck() const;
    private:
        string name;
        string ssn;
        double netPay;
    };

    Employee::Employee() : name("No name yet"), ssn("No number yet"), netPay(0)
    {
        //deliberately empty
    }

    Employee::Employee(const string& theName, const string& theNumber)
        : name(theName), ssn(theNumber), netPay(0)
    {
        //deliberately empty
    }

    string Employee::getName() const
    {
        return name;
    }

    string Employee::getSsn() const
    {
        return ssn;
    }

    double Employee::getNetPay() const
    {
        return netPay;
    }

    void Employee::setName(const string& newName)
    {
        name = newName;
    }

    void Employee::setSsn(const string& newSsn)
    {
        ssn = newSsn;
    }

    void Employee::setNetPay(double newNetPay)
    {
        netPay = newNetPay;
    }

    void Employee::printCheck() const
    {
        cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
            << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
            << "Check with the author of the program about this bug.\n";
        exit(1);
    }

}//SavitchEmployees
namespace SavitchEmployees
{
    class SalariedEmployee : public Employee
    {
    public:
        SalariedEmployee();
        SalariedEmployee(const string& theName, const string& theSsn,
            double theWeeklySalary);
        double getSalary() const;
        void setSalary(double newSalary);
        void printCheck();
    private:
        double salary;//weekly
    };
    SalariedEmployee::SalariedEmployee() : Employee(), salary(0)
    {
        //deliberately empty
    }

    SalariedEmployee::SalariedEmployee(const string& newName, const string& newNumber,
        double newWeeklyPay)
        : Employee(newName, newNumber), salary(newWeeklyPay)
    {
        //deliberately empty
    }

    double SalariedEmployee::getSalary() const
    {
        return salary;
    }

    void SalariedEmployee::setSalary(double newSalary)
    {
        salary = newSalary;
    }

    void SalariedEmployee::printCheck()
    {
        setNetPay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << getName() << endl;
        cout << "The sum of " << getNetPay() << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Salaried Employee. Regular Pay: "
            << salary << endl;
        cout << "_________________________________________________\n";
    }
}
namespace SavitchEmployees
{
    class Doctor : public SalariedEmployee
    {

    public:
        //Constructor
        Doctor() { SalariedEmployee(); }
        Doctor(string _v1, double _v2) : SalariedEmployee(), speciality(_v1), officeFee(_v2) {}
        Doctor(Doctor& _D1) :SalariedEmployee(_D1.getName(), _D1.getSsn(), _D1.getSalary()), speciality(_D1.getSpeciality()), officeFee(_D1.getOfficeFee()) {}
        //Accessor and Mutator
        void setSpeciality(string _value) { speciality = _value; };
        string getSpeciality() { return speciality; }
        void setOfficeFee(double _value) { officeFee = _value; };
        double getOfficeFee() { return officeFee; }
        //Assignment operator 
        Doctor& operator =(Doctor& _D1)
        {
            setName(_D1.getName()); setName(_D1.getName()); setSalary(_D1.getSalary());
            speciality = _D1.getSpeciality(); officeFee = _D1.getOfficeFee();
            return *this;
        }

        void inputData()
        {
            cout << "\n__________________________________________________\n";
            cout << "Input data of Speciality" << endl; cin >> speciality;
            cout << "Input data of OfficeFee" << endl; cin >> officeFee;
            cout << "_________________________________________________\n";
        }
        void printCheck()
        {
            cout << "\n__________________________________________________\n";
            cout << "Speciality is " << speciality << endl;
            cout << "OfficeFee is" << officeFee << endl;
            cout << "_________________________________________________\n";
        }
    protected:
        double officeFee;
    private:
        string speciality;
    };
}