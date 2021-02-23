#include "iostream"
#include "sudoku.h"
using namespace std;

int main(void)
{
    Sudoku Sudoku;
    Sudoku.readFile("input.txt");
    Sudoku.show();
    Sudoku.solve();
    cout << "\n\n";
    Sudoku.show();
    Sudoku.writeFile("output.txt");

    return 0;
}
