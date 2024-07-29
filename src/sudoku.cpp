//
// Created by Keshav Bhandari on 2/7/24.
//
//Purpose: Finds the solution to the sudoku problem
//pre-conditions: Three funcitons are used for formatting, validating, and solving each cell.

#include "../include/sudoku.h"
#include <iostream>
using namespace std;

//Purpose: formats and displays the board with colors, symbols and alignments
void printBoard(int** BOARD, int r, int c, int k)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            string board_piece;
            // If boardpiece is 0 then, yellow colour is assigned to it
            if (BOARD[i][j] == 0) board_piece = "\x1B[93m-\x1B[0m";
                // If boardpiece is non zero, then converted to string
            else board_piece = to_string(BOARD[i][j]);
            if ((i == r && j == c) && k != 0)
            {
                if (isValid(BOARD, r, c, k))
                    board_piece = "\x1B[32m" + to_string(k) + "\x1B[0m"; // If entry is correct, number is displayed in green
                else
                    board_piece = "\x1B[31m" + to_string(k) + "\x1B[0m"; // If entry is incorrect, number is displayed in red
            }
            cout << board_piece;
            if (j == 2 || j == 5) cout << " | "; // "|" added after interval of three columns
            else cout << " ";
        }
        // After three rows, line of 21 dots are added
        if (i == 2 || i == 5)
        {
            cout << endl;
            for (int l = 0; l < 21; l++) cout << ".";
        }
        cout << endl;
    }
}

//Purpose: Checks the validity of each number from 1 to 9 for one location
//Procedure: Checks if it matches with other element in the row, colomn and 3x3 region
//Post-condition: After two conditions are false, the value is passed to printboard() function.

bool isValid(int** BOARD, int r, int c, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (k == BOARD[r][i] || k == BOARD[i][c])// If k matches other numbers in that row or column
            return false;
    }

    for (int i = 3 * (r / 3); i < 3 * (r / 3) + 3; i++) // If k matches other numbers in its 3x3 region
    {
        for (int j = 3 * (c / 3); j < 3 * (c / 3) + 3; j++)
        {
            if (k == BOARD[i][j])
                return false;
        }
    }
    return true;
}

bool solveBoard(int** BOARD, int r, int c){
    if(r == 9) // If r has reached 9 then all the rows has been dealt with. Hence sudoku is solved.
        return true;
    else if(c == 9) // If c reached 9 then the operation is to be run on the next row.
        return solveBoard(BOARD, r+1, 0);
    else if(BOARD[r][c] != 0) // If the the value at that index is non-zero then program moves to next element.
        return solveBoard(BOARD, r, c+1);
    else{
        for(int k=1; k<10; k++){
            if(isValid(BOARD, r, c, k)){ // checks if the value of k can be placed at that point validating the isValid function.
                BOARD[r][c] = k;
                if(solveBoard(BOARD, r, c+1)) // Moves to next cell and does the same for next cell (c+1)
                    return true;
                else
                    BOARD[r][c] = 0; // If solution is not found then it resets that element to zero again
            }
        }
        return false;
    }
}