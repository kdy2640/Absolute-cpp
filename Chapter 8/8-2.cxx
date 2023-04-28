#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class Rational {
public:
    Rational(int num, int den) : num(num), denom(den) {}
    Rational(int whole) : num(whole), denom(1) {}
    Rational() : num(0), denom(1) {}

    friend Rational operator +(const Rational& q1, const Rational& q2);
    friend Rational operator -(const Rational& q1, const Rational& q2);
    friend Rational operator *(const Rational& q1, const Rational& q2);
    friend Rational operator /(const Rational& q1, const Rational& q2);

    friend bool operator ==(const Rational& q1, const Rational& q2);
    friend bool operator >(const Rational& q1, const Rational& q2);
    friend bool operator <(const Rational& q1, const Rational& q2);
    friend bool operator >=(const Rational& q1, const Rational& q2);
    friend bool operator <=(const Rational& q1, const Rational& q2);

    int getnum() const { return num; };
    int getdenom() const { return denom; };
private:
    int num = 0;
    int denom = 1;
};
void printNormal(Rational q1)
{
    int num = abs(q1.getnum());
    int denom = abs(q1.getdenom());
    int small = min(num, denom);
    for (int i = small; i > 1; i--) {
        if ((num % i) == 0 && (denom % i) == 0) {
            num = num / i;
            denom = denom / i;
        }
        if (num == 1 || denom == 1) {
            break;
        }
    }
    cout << "The Normalized is: ";
    if (num < 0) {
        cout << "-";
    }
    cout << num << "/" << denom << endl;
}

Rational operator +(const Rational& q1, const Rational& q2) {
    Rational ans;
    if (q1.denom == q2.denom) {
        ans.num = q1.num + q2.num;
        ans.denom = q1.denom;
    }
    else {

        ans.num = q1.num * q2.denom + q2.num * q1.denom;
        ans.denom = q1.denom * q2.denom;
    }
    return ans;
}
Rational operator -(const Rational& q1, const Rational& q2) {
    Rational ans;
    if (q1.denom == q2.denom) {
        ans.num = q1.num - q2.num;
        ans.denom = q1.num;
    }
    else {
        ans.num = q1.num * q2.denom - q1.denom * q2.num;
        ans.denom = q1.denom * q2.denom;
    }
    return ans;
}
Rational operator *(const Rational& q1, const Rational& q2) {
    Rational answer;
    answer.num = q1.num * q2.num;
    answer.denom = q1.denom * q2.denom;
    return answer;
}
Rational operator /(const Rational& q1, const Rational& q2) {
    Rational answer;
    answer.num = q1.num * q2.denom;
    answer.denom = q1.denom * q2.num;
    return answer;
}
bool operator ==(const Rational& q1, const Rational& q2) {
    return ((q1.num * q2.denom) == (q1.denom * q2.num));
}
bool operator >(const Rational& q1, const Rational& q2) {
    return ((q1.num * q2.denom) > (q2.num * q1.denom));
}
bool operator <(const Rational& q1, const Rational& q2) {
    return ((q1.num * q2.denom) < (q2.num * q1.denom));
}
bool operator >=(const Rational& q1, const Rational& q2) {
    return (((q1.num * q2.denom) > (q2.num * q1.denom))
        || (q1.num * q2.denom) == (q2.num * q1.denom));
}
bool operator <=(const Rational& q1, const Rational& q2) {
    return (((q1.num * q2.denom) < (q2.num * q1.denom))
        || (q1.num * q2.denom));
}

int main() {
    Rational q1(97, 25), q2(-45, 67), q3;
    cout << "A : " << q1.getnum() << "/" << q1.getdenom() << " , ";
    cout << "B : " << q2.getnum() << "/" << q2.getdenom() << endl;
    q3 = q1 + q2; cout << "A + B = " << q3.getnum() << "/" << q3.getdenom() << " , ";
    q3 = q1 - q2; cout << "A - B = " << q3.getnum() << "/" << q3.getdenom() << endl;
    q3 = q1 * q2; cout << "A * B = " << q3.getnum() << "/" << q3.getdenom() << " , ";
    q3 = q1 / q2; cout << "A / B = " << q3.getnum() << "/" << q3.getdenom() << endl << endl;

    if (q1 == q2) cout << q1.getnum() << "/" << q1.getdenom() << " == " << q2.getnum() << "/" << q2.getdenom() << endl;
    else  cout << q1.getnum() << "/" << q1.getdenom() << " != " << q2.getnum() << "/" << q2.getdenom() << endl;

    if (q1 > q2) cout << q1.getnum() << "/" << q1.getdenom() << " > " << q2.getnum() << "/" << q2.getdenom() << " , ";
    else cout << q1.getnum() << "/" << q1.getdenom() << " <= " << q2.getnum() << "/" << q2.getdenom() << " , ";

    if (q1 >= q2) cout << q1.getnum() << "/" << q1.getdenom() << " >= " << q2.getnum() << "/" << q2.getdenom() << endl;
    else cout << q1.getnum() << "/" << q1.getdenom() << " < " << q2.getnum() << "/" << q2.getdenom() << endl;

    cout << endl;
    cout << q2.getnum() << "/" << q2.getdenom() << " ";
    printNormal(q2);
    cout << endl;
    return 0;
}