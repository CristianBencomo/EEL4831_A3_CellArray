#include "cell.h"
#include <iostream>
#include <cstdio>

class Cell
{
    typedef void (Cell::*funcPointer)(int);
    funcPointer *funcArray = new funcPointer[3];
    
    private:
        // static funcPointer *funcArray;
        int x,y,z,funcIndex;        
        
        void f1(int x)
        {
            std::cout << "I am f1, my value is " << x << std::endl;
        }

        void f2(int x)
        {
            std::cout << "I am f2, my value is " << x << std::endl;
        }

        void f3(int x)
        {
            std::cout << "I am f3, my value is " << x << std::endl;
        }

        void callFunc(int index)
        {
            int val = rand()%99 +1;
            (this->*funcArray[index])(val);
        }

    public:
        void funcArrayGen()
        {
            funcArray[0] = &Cell::f1;
            funcArray[1] = &Cell::f2;
            funcArray[2] = &Cell::f3;
        }

        void tick()
        {
            std::printf("This cell is located at X: %d\tY: %d\tZ:%d\n", x, y, z);
            callFunc(funcIndex);

        }
        
        inline Cell(int x, int y, int z)
        {
            Cell::x = x;
            Cell::y = y;
            Cell::z = z;

            srand(time(0));
            funcIndex = rand()%3;
        }        
};