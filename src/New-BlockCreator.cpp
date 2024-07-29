#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()


using namespace std;

void shuffleArray(int arr[], int size) {
    srand(time(nullptr));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int fillBox ( int** BOARD, int start){
    int SIZE=9;
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    shuffleArray(numbers, SIZE);


    for (int start=0; start<3; start++){
    for (int i = start; i<start+3; i++){
        for (int j = start; j<start+3; j++){
            BOARD[i][j] = numbers [i*3+j];
        }
    }
    }
    return 0;
}


int randNum(int lower_bound, int upper_bound){

    srand(time(0));

    return lower_bound + rand() % (upper_bound - lower_bound +1);

}

