#ifndef MAP_H
#define MAP_H

class Map{
    private:
    int rowSize;
    int colSize;
    char** arr;

    public:
    Map(int row, int col);
    ~Map();
    char getMapContent(int row, int col) const;
    void setMapContent(int row, int col, char val);
    int getRowSize() const;
    int getColumnSize() const;
};
#endif
