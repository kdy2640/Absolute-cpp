
#include <iostream>
using namespace std;
class Prime {
public:
    Prime();
    Prime(int n);
    int getnum() const;
    Prime operator ++(int);
    Prime operator --(int);
private:
    int num;
    bool isPrime(int n);
    int prevPrime(int n);
    int nextPrime(int n); 
};
Prime::Prime() : num(1) {}
Prime::Prime(int n) : num(n) {}
int Prime::getnum() const { return num; }

bool Prime::isPrime(int n) {
    bool result = true;
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}
int Prime::nextPrime(int n) {
    int next = 0;
    while (true) {
        n++;
        if (isPrime(n)) {
            next = n;
            break;
        }
    }
    return next;
}
int Prime::prevPrime(int n) {
    int next = 0;
    if (n <= 2) return -1;
    while (true) {
        n--;
        if (isPrime(n)) {
            next = n;
            break;
        }
    }
    return next;
}
Prime Prime::operator ++(int) {
    Prime pn;
    pn.num = nextPrime(num);
    return pn;
}
Prime Prime::operator --(int) {
    Prime pn;
    pn.num = prevPrime(num);
    return pn;
}
int main() {
    Prime minus, p(13), plus;
    minus = p--;
    plus = p++;
    cout << "previous prime is: " << minus.getnum() << endl;
    cout << "prime is: " << p.getnum() << endl;
    cout << "next prime is: " << plus.getnum() << endl;
    cout << endl;
    return 0;
}