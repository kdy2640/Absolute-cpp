
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
namespace Fig
{

    class Figure {
    public:
        virtual void erase() {
            cout << "Figure Call erase()" << endl;
        }

        virtual void draw() {
            cout << "Figure Call draw() " << endl;
        }

        void center() {
            cout << "center() call" << endl;
            erase();
            draw();
        }
    };

    class Rectangle : public Figure {
    public:
        void erase() {
            cout << "Rectangle call erase()" << endl;
        }

        void draw() {
            cout << "Rectangle call draw() " << endl;
        }
    };

    class Triangle : public Figure {
    public:
        void erase() {
            cout << "Triangle call erase()" << endl;
        }

        void draw() {
            cout << "Triangle call draw() " << endl;
        }
    };

}
