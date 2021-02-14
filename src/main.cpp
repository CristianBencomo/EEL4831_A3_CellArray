#include "cell.cpp"
#include <string>
#include <iostream>

Cell ****array;
int x, y, z;

void cellArrayGen()
{
    array = new Cell ***[x];

    for (int i = 0; i < x; i++)
    {
        array[i] = new Cell **[y];

        for (int j = 0; j < y; j++)
        {
            array[i][j] = new Cell  *[z];

            for (int k = 0; k < z; k++)
            {
                array[i][j][k] = new Cell(i,j,k);
            }
        }
    }
}

void cellArrayDelete()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
            {
                delete[] array[i][j][k];
            }
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete array;
}

int main(int argc, char const *argv[])
{
    std::string userAnswer;

    do
    {
        cellArrayGen();

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < z; k++)
                {
                    array[i,j,k];
                }
            }
        }

        cellArrayDelete();

        std::cout << "Would you like to run the programn again? (Y/N)" << std::endl;
        std::cin >> userAnswer;
    } while (userAnswer.compare("N"));
    
    std::cout << "This is a test" << std::endl;


    return 0;
}
