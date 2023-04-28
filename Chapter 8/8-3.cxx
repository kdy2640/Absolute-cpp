#include <iostream>
#include <cctype>
using namespace std;

class Complex {
public:
    Complex(double r, double i) : real(r), com(i) {}
    Complex(double r) : real(r), com(0) {}
    Complex() : real(0), com(0) {}

    friend Complex operator == (const Complex& c1, const Complex& c2);
    friend Complex operator + (const Complex& c1, const Complex& c2);
    friend Complex operator - (const Complex& c1, const Complex& c2);
    friend Complex operator * (const Complex& c1, const Complex& c2);
    friend istream& operator >> (istream& is, Complex& c);
    friend ostream& operator << (ostream& os, const Complex& c);
private:
    double real;
    double com;
};

Complex operator ==(const Complex& c1, const Complex& c2) {
    return (c1.real == c2.real && c1.com == c2.com);
}
Complex operator +(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.com + c2.com);
}
Complex operator -(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.com - c2.com);
}
Complex operator *(const Complex& c1, const Complex& c2) {
    Complex ans;
    ans.real = c1.real * c2.real - c1.com * c2.com;
    ans.com = c1.real * c2.com + c1.com * c2.real;
    return ans;
}
ostream& operator <<(ostream& out, const Complex& c) {
    out << "( " << c.real << " + " << c.com << "i)";
    return out;
}
istream& operator >>(istream& in, Complex& c) {
    char ch;
    in >> ch >> c.real >> ch >> c.com >> ch;
    return in;
}

int main() {
    Complex c1(1, 1), c2(-1, 1), c3;
    cout << "A : " << c1 << " , ";
    cout << "B : " << c2 << endl;
    c3 = c1 + c2; cout << "A + B = " << c3 << endl;
    c3 = c1 - c2; cout << "A - B = " << c3 << endl;
    c3 = c1 * c2; cout << "A * B = " << c3 << endl;
    cout << endl;
}

