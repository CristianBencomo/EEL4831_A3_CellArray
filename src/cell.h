#ifndef CELL_H
#define CELL_H

class Cell
{
    typedef void (Cell::*funcPointer)(int);
    funcPointer *funcArray = new funcPointer[3];
    
    private:


    public:
        void funcArrayGen();
        void tick();
        inline Cell(int x, int y, int z);
};

#endif