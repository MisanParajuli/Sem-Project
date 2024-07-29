//
// Created by Keshav Bhandari on 2/7/24.
//

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H
void printBoard(int**, int, int, int);
bool isValid(int**, int, int, int);
bool solveBoard(int**, int, int);
int** generateBoard();
#endif //SUDOKUPROJECT_SUDOKU_H
