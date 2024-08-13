#include "Executive.h"
#include <iostream>

Executive::Executive(std::string fileName)
{
    counter = 0;
    inputFile.open(fileName);
    try{
        if(inputFile.is_open())
        {
            inputFile >> rowSize;
            inputFile >> colSize;
            if(rowSize < 1 || colSize < 1){
                throw(std::runtime_error("\nERROR: Row and column sizes need to be at least 1."));
            }
            inputFile >> startRow;
            inputFile >> startCol;
            if(startRow < 0 || startRow >= rowSize || startCol < 0 || startCol >= colSize){
                throw(std::runtime_error("\nERROR: Start position must be in range. "));
            }
            map = new Map(rowSize, colSize);
            for(int i=0; i< rowSize; i++)
            {
                for(int j=0; j<colSize; j++)
                {
                    inputFile >> mapval;
                    map->setMapContent(i, j, mapval);
                }
            }
        }
        else{
            throw(std::runtime_error("File was not opened."));
        }
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what();
    }
}



void Executive::sewerFind(Map* map, int rowSize, int colSize)
{

    for(int i=0; i<rowSize; i++){
        for(int j=0; j<colSize; j++){
            if(map->getMapContent(i, j) == '@'){
                counter++;
            }
        }
    }
    sewerRow = new int[counter];
    sewerCol = new int[counter];
    for(int i=0; i<counter-1; i++){
        for(int j=0; j<rowSize; j++){
            for(int k=0; k<colSize; k++){
                if(map->getMapContent(j, k) == '@'){
                    sewerRow[i] = j;
                    sewerCol[i] = k;
                }
            }
        }
    }
}

void Executive::navigateMap(Map* map, int row, int col, int rowSize, int colSize)
{
    if(map->getMapContent(row, col) == 'S'){
        map->setMapContent(row, col, 'B');
    }

    if(row-1 >= 0 && map->getMapContent(row-1, col) == 'S'){
        navigateMap(map, row-1, col, rowSize, colSize);
    }
    if(row-1 >= 0 && map->getMapContent(row-1, col) == '@'){
        for(int i=0; i<counter-1; i++){
        navigateMap(map, sewerRow[i], sewerCol[i], rowSize, colSize);
        }
    }
    if(col+1 < colSize && map->getMapContent(row, col+1) == 'S'){
        navigateMap(map, row, col+1, rowSize, colSize);
    }
    if(col+1 < colSize && map->getMapContent(row, col+1) == '@'){
        for(int i=0; i<counter-1; i++){
        navigateMap(map, sewerRow[i], sewerCol[i], rowSize, colSize);
        }
    }
    if(row+1 < rowSize && map->getMapContent(row+1, col) == 'S'){
        navigateMap(map, row+1, col, rowSize, colSize);
    }
    if(row+1 < rowSize && map->getMapContent(row+1, col) == '@'){
        for(int i=0; i<counter-1; i++){
        navigateMap(map, sewerRow[i], sewerCol[i], rowSize, colSize);
        }
    }
    if(col-1 >= 0 && map->getMapContent(row, col-1) == 'S'){
        navigateMap(map, row, col-1, rowSize, colSize);
    }
    if(col-1 >= 0 && map->getMapContent(row, col-1) == '@'){
       for(int i=0; i<counter-1; i++){
        navigateMap(map, sewerRow[i], sewerCol[i], rowSize, colSize);
        }
    }
}   

void Executive::printMap(Map* map, int rowSize, int colSize){
    for(int i=0; i<rowSize; i++){
        std::cout << "\n";
        for(int j=0; j<colSize; j++){
            std::cout << map->getMapContent(i, j) << "\t";
        }
    }
    std::cout << "\n";
}

void Executive::run()
{
    sewerFind(map, rowSize, colSize);
    navigateMap(map, startRow, startCol, rowSize, colSize);
    printMap(map, rowSize, colSize);
    delete [] sewerRow;
    delete [] sewerCol;
    delete map;
}
