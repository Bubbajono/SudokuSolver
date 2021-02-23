#include "sudoku.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

Sudoku::Sudoku()
{
}

Sudoku::Sudoku(std::vector<std::vector<int>> sudoku)
{
    this->sudoku = sudoku;
}

bool Sudoku::solve()
{
    int row, column;
    
    //First find empty - if no empty then sudoku is solved
    //Pass reference to row and column to update
    if (!CanFindEmpty(row, column))
    {
        IsSolved = true;
        return true;
    }

    //Test possible numbers
    for (int number : numbers)
    {
        //If possible: assign
        if (IsPossible(row, column, number))
        {
            sudoku[row][column] = number;

            //Loop over other zeros in the grid
            if (Sudoku::solve())
            {
                //Breakpoint if a solution is found
                IsSolved = true;
                return true;
            }

            //Set point to zero to search for other solutions
            sudoku[row][column] = 0;
        }
    }

    return false;
}

void Sudoku::show()
{
    for (int i=0; i<sudoku.size();i++)
    {
        for (int j=0; j<sudoku[i].size();j++)
        {
            cout << std::to_string(sudoku[i][j]) + " ";
        }
        cout << "\n";
    }
}

void Sudoku::readFile(std::string filename)
{
    ifstream file(filename);
    std::string readRow;
    std::vector<int> writeRow;
    std::vector<std::vector<int>> out; 

    while (getline(file, readRow)) 
    {
        for (char c : readRow)
        {
            if (isdigit(c))
            {
                writeRow.push_back(c - '0'); //Convert from ASCII to int
            }
        }
        out.push_back(writeRow);
        writeRow.clear();
    }

    file.close();

    sudoku = out;
}

void Sudoku::writeFile(std::string filename)
{
    ofstream file(filename);

    for (int i=0; i<sudoku.size();i++)
    {
        for (int j=0; j<sudoku[i].size();j++)
        {
            file << std::to_string(sudoku[i][j]) + " ";
        }
        file << "\n";
    }

    file.close();
}

bool Sudoku::IsPresentInColumn(int column, int number)
{
    for (int row = 0; row < 9; row++)
    {
        if (sudoku[row][column] == number)
        {
            return true;
        }
    }
    return false;
}

bool Sudoku::IsPresentInRow(int row, int number)
{
    for (int column = 0; column < 9; column++)
    {
        if (sudoku[row][column] == number)
        {
            return true;
        }
    }
    return false;
}

bool Sudoku::IsPresentInBox(int rowStart, int columnStart, int number)
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (sudoku[row + rowStart][column + columnStart] == number)
            {
                return true;
            } 
        }
    }
    return false;
}

bool Sudoku::IsPossible(int row, int column, int number)
{
    //Calculate relevant 3by3 grid
    int rowStart = row - row%3;
    int columnStart = column - column%3;

    bool IsPresentInColumn = Sudoku::IsPresentInColumn(column, number);
    bool IsPresentInRow = Sudoku::IsPresentInRow(row, number);
    bool IsPresentInBox = Sudoku::IsPresentInBox(rowStart, columnStart, number);
    
    return (!IsPresentInColumn 
                && !IsPresentInRow 
                    && !IsPresentInBox);
}

bool Sudoku::CanFindEmpty(int &row, int &column)
{
    for (row = 0; row < 9; row++)
    {
        for (column = 0; column < 9; column++)
        {
            if (sudoku[row][column] == 0)
            {
                return true;
            }
        }
    }
    return false;
}