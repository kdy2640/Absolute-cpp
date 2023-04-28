#include <iostream>
#include <cmath> 
#include <cstdlib> 
#include <vector>
using namespace std;
class Inte {
public:
    void setInte(int a);
    void setValue();
    int getInte() const;
    int getSize();
    int& operator [](int a);
private:
    int size;
    vector<int> arr;
    int inte;
};

void Inte::setInte(int a) {
    inte = a;
    size = getSize();
}
int Inte::getInte() const { return inte; }
void Inte::setValue() {
    int number = inte;
    int counter = 0;
    while (number > 0) {
        arr.push_back(number % 10);
        number = number / 10;
        counter++;
    }
}
int Inte::getSize() {
    return  log10((double)inte) + 1;
}
int& Inte::operator [](int a) {
    if (a > size) {
        cout << "size over";
        exit(1);
    }
    else {
        return arr[a];
    }
}

int main() {
    Inte a;
    a.setInte(152364);
    a.setValue();
    for (int i = 0; i < a.getSize(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}