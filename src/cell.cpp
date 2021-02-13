#include <iostream>
#include <cstdio>

class Cell
{
    private:
        typedef void (*Cell::funcPointer)(int);
        static funcPointer *funcArray;
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
            (*(funcArray[index]))(val);
        }

    public:
        void funcArrayGen()
        {
            funcArray = new Cell::funcPointer[3];
            funcArray[0] = &f1;
            funcArray[1] = &f2;
            funcArray[2] = &f3;
        }

        void tick()
        {
            std::printf("This cell is located at X: %d\tY: %d\tZ:%d\n", x, y, z);

        }
        
        Cell(int x, int y, int z)
        {
            Cell::x = x;
            Cell::y = y;
            Cell::z = z;

            srand(time(0));
            funcIndex = rand()%3;
        }



        
};