
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
    class Administrator : protected SalariedEmployee
    {

    public:
        Administrator() { SalariedEmployee(); }
        void setSupervisor(string _name) :immediateSupervisor(_name) {}
        void inputData()
        {
            cout << "\n__________________________________________________\n";
            cout << "Input data of Title" << endl; cin >> Title;
            cout << "Input data of responsibility" << endl; cin >> responsibility;
            cout << "Input data of ImmediateSupervisor" << endl; cin >> ImmediateSupervisor;
            cout << "Input data of annualSalary" << endl; cin >> annualSalary;


            cout << "_________________________________________________\n";
        }
        void print()
        {
            cout << "\n__________________________________________________\n";
            cout << "Title is" << title << endl;
            cout << "Responsibility is " << responsibility() << endl;
            cout << "ImmediateSupervisor is " << immediateSupervisor << endl;
            cout << "annualSalary is " << annualSalary << endl;
            cout << "_________________________________________________\n";

        }
        void printcheck()
        {
            cout << "\n__________________________________________________\n";
            cout << "Title is" << title << endl;
            cout << "Responsibility is " << responsibility() << endl;
            cout << "ImmediateSupervisor is " << immediateSupervisor << endl;
            cout << "annualSalary is " << annualSalary << endl;
            cout << "_________________________________________________\n";
        }
    protected:
        double annualSalary;
    private:
        string title;
        string responsibility;
        string immediateSupervisor;
    };
}
