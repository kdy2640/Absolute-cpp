
#include <iostream>
using namespace std;
class Temper {
public:
    Temper(int t) :temper(t) {};
    Temper() : temper(0) {};
    friend istream& operator >>(istream& is, Temper& t);
    friend ostream& operator <<(ostream& os, const Temper& t);
    friend bool operator ==(const Temper& t1, const Temper& t2);
private:
    double temper;
};
bool operator ==(const Temper& t1, const Temper& t2) {
    return (t1.temper == t2.temper);
}
istream& operator >>(istream& is, Temper& t) {
    is >> t.temper;
    return is;
}
ostream& operator <<(ostream& os, const Temper& t) {
    os << "temper is: " << t.temper;
    return os;
}
int main() {
    Temper t, t2(28);
    cout << "input the desire temperature (now is 28) :";
    cin >> t;
    if (t == t2) cout << "same!" << endl;
    cout << t;
    cout << endl;
    return 0;
}