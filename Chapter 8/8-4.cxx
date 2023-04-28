
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;
class CharPair {
public:
    CharPair();
    CharPair(int sz);
    CharPair(int sz, char parr[]);

    int getSize() const;

    char& operator [](const int index);
private:
    char arr[100];
    int size;
};
CharPair::CharPair() {
    size = 10;
    for (int i = 0; i < size; i++) {
        arr[i] = '#';
    }
}
CharPair::CharPair(int sz) {
    if (sz > 100) {
        cout << "size cant over 100";
        exit(1);
    }
    for (int i = 0; i < sz; i++) {
        arr[i] = '#';
    }
}
CharPair::CharPair(int sz, char parr[]) {
    if (sz > 100) {
        cout << "size cant over 100";
        exit(1);
    }
    for (int i = 0; i < sz; i++) {
        arr[i] = parr[i];
    }
}

int CharPair::getSize() const {
    return size;
}
char& CharPair::operator [](int i) {
    if (i >= 100) {
        cout << "invalid index.";
        exit(1);
    }
    else {
        return arr[i];
    }
}

int main() {
    CharPair p;
    p[5] = 'b';
    cout << p[3] << endl;
    cout << p[5] << endl;
    char arr[3] = { '1', '2', '3' };
    CharPair chp(3, arr);
    cout << chp[1] << endl;
    return 0;
}