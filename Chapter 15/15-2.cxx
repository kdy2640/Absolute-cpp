
#include <string>
#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;

namespace Fig
{

    class Figure {
    public:
        void erase() {
            system("cls");
        }

        virtual void draw() {
            cout << "Figure Call draw() " << endl;
        }

        void center() {
            erase();
            draw();
        }
    };

    class FRectangle : public Figure {
    public:
        FRectangle(int _width, int _height) :width(_width), height(_height)
        {
            if (width > 12 || height > 12) exit(1);
            Table = new char* [height];
            for (int i = 0; i < height; i++) {
                Table[i] = new char[width];
            }
            for (int i = 0; i < width; i++)
            {
                Table[0][i] = '*';
                Table[height - 1][i] = '*';
            }
            for (int i = 0; i < height; i++)
            {
                Table[i][0] = '*';
                Table[i][width - 1] = '*';
            }
        }
        void draw() {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (Table[i][j] != '*') cout << " ";
                    else cout << Table[i][j];
                }
                cout << endl;
            }

        }
        ~FRectangle()
        {
            for (int i = 0; i < height; i++) {
                delete[] Table[i];
            }
            delete[] Table;
        }
    private:
        char** Table;
        int width;
        int height;
    };

    class FTriangle : public Figure {
    public:
        FTriangle(int _width) :width(_width), height(_width + 2)
        {
            if (width > 15 || height > 15) exit(1);
            Table = new char* [height];
            for (int i = 0; i < height; i++) {
                Table[i] = new char[width];
            }

            for (int j = 0; j < width; j++)
            {
                Table[height - 1][j] = '*';
            }
            if (_width % 2 == 0) //礎熱 a/2 類 +1
            {
                int max = width - 2;
                for (int i = 0; i < max; i++)
                {
                    Table[height - 2 - i][1 + (i / 2)] = '*';
                    Table[height - 2 - i][width - 2 - (i / 2)] = '*';
                }
                Table[height - 2 - max][width / 2 - 1] = '*';
            }
            else // �汝� a+1/2 類
            {
                int max = width - 1;
                for (int i = 0; i < max; i++)
                {
                    Table[height - 2 - i][1 + (i / 2)] = '*';
                    Table[height - 2 - i][width - 2 - (i / 2)] = '*';
                }
            }
        }
        void draw() {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (Table[i][j] != '*') cout << " ";
                    else cout << Table[i][j];
                }
                cout << endl;
            }

        }
        ~FTriangle()
        {
            for (int i = 0; i < height; i++) {
                delete[] Table[i];
            }
            delete[] Table;
        }
    private:
        char** Table;
        int width;
        int height;
    };

}
