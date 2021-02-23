#include <iostream>
#include <string>
#include <vector>
#ifndef SUDOKU_H // include guard
#define SUDOKU_H

class Sudoku
{
    int numbers[9] = {1,2,3,4,5,6,7,8,9};
    std::vector<std::vector<int>> sudoku;
    bool IsSolved;
    public:
        Sudoku();
        Sudoku(std::vector<std::vector<int>> sudoku);
        bool solve();
        void show();
        void readFile(std::string filename);
        void writeFile(std::string filename);
    private:
        bool IsPresentInColumn(int column, int number);
        bool IsPresentInRow(int row, int number);
        bool IsPresentInBox (int rowStart, int colStart, int number);
        bool IsPossible(int row, int column, int number);
        bool CanFindEmpty(int &row, int &column);
};  

#endif