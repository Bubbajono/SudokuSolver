#include "sudoku.h"
#include <iostream>
#include <string>

using namespace std;

Sudoku::Sudoku()
{
    cout << "Sudoku Class Constructed with Default Constructor\n\n\n\n\n";
}

Sudoku::Sudoku(std::string CustomConstructorMessage)
{
    cout << CustomConstructorMessage + "\n\n\n\n\n";
}