
#include <iostream>
#include <cctype>
using namespace std;

class Vector2D {
public:
    Vector2D(int vx, int vy) :x(vx), y(vy) {};
    Vector2D() :x(0), y(0) {};
    void setX(int x);
    void setY(int x);
    int getX() const;
    int getY() const;
    friend int operator *(const Vector2D& v1, const Vector2D& v2);
private:
    int x;
    int y;
};

void Vector2D::setX(int x) {
    x = x;
}
int Vector2D::getX() const { return x; }
void Vector2D::setY(int x) {
    y = y;
}
int Vector2D::getY() const { return y; }

int operator *(const Vector2D& v1, const Vector2D& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}
int main() {

    Vector2D v1(3, 6), v2(5, 7);
    cout << "dot product is: " << v1 * v2 << endl;
    return 0;
}