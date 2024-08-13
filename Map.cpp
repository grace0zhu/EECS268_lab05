#include "Map.h"
#include <fstream>

Map::Map(int row, int col)
{
    rowSize = row;
    colSize = col;
    arr = new char*[rowSize];
    for(int i=0; i<rowSize; i++)
    {
        {
            arr[i] = new char[colSize];
        }
    }
}
Map::~Map()
{
    for(int i=0; i<rowSize; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
char Map::getMapContent(int row, int col) const
{
    return(arr[row][col]);
}
void Map::setMapContent(int row, int col, char val)
{
    rowSize = row;
    colSize = col;
    arr[row][col] = val;
}
int Map::getRowSize() const
{
    return(rowSize);
}
int Map::getColumnSize() const
{
    return(colSize);
}
