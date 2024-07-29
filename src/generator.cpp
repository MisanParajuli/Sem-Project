// Sample

#include "../include/sudoku.h"
#include "../include/New-Blockcreater.h"
#include "../include/main.h"



int** generateBoard(){
    // Following initialization is important
    int** BOARD = new int*[9];
    for(int i = 0; i < 9; i++){
        BOARD[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }

    for (int start = 0; start <3; start++) {
            fillBox (BOARD, start)
    }

    solveBoard (BOARD, 0, 0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (randNum(1,100)<50){
                    BOARD[i][j] = 0;
                    }
        }
    }
    return BOARD;
}
