#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <fstream>
#include "Map.h"

class Executive
{
    private:
    std::ifstream inputFile;
    int rowSize;
    int colSize;
    int startRow;
    int startCol;
    char mapval;
    int counter;
    int* sewerRow;
    int* sewerCol;
    Map* map;

    public:
    Executive(std::string fileName);
    void sewerFind(Map* map, int rowSize, int colSize);
    void navigateMap(Map* map, int startRow, int startCol, int rowSize, int colSize);
    void printMap(Map* map, int rowSize, int colSize);
    void run();

};

#endif
