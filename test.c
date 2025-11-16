#include <stdio.h>
#include <stdbool.h>

//Function for Printing The Whole Board.
void printBoard(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

//Fuction for Validity Check.
bool isValid(int board[9][9], int row, int col, int d) {


    // horizontal check
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == d) {
            return false;
        }
    }


    // vertical check
    for (int j = 0; j < 9; j++) {
        if (board[j][col] == d) {
            return false;
        }
    }


    // grid check
    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;
    for (int i = srow; i < srow + 3; i++) {
        for (int j = scol; j < scol + 3; j++) {
            if (board[i][j] == d) {
                return false;
            }
        }
    }
    return true;
}

//Fucntion for Backtracking.
bool solver(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {  
                for (int d = 1; d <= 9; d++) {
                    if (isValid(board, i, j, d)) {
                        board[i][j] = d;
                        if (solver(board) == true) {
                            return true;
                        }
                        board[i][j] = 0;  
                    }
                }
                
                return false;
            }
        }
    }
   
    return true;
}

int main() {
    int board[9][9] = {
        {0, 0, 0, 0, 7, 0, 0, 0, 0},
        {3, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {2, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 9, 0, 0, 0},
        {1, 6, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };


   // Checks For valid Numbers
    for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        if(board[i][j] < 0 || board[i][j] > 9){
            printf("Invalid INPUT BRooo");
            return 1;
        }
    }
}

    if (solver(board)) {
        printf("SOLVED SUDOKU:\n");
        printBoard(board);
    } else {
        printf("NO SOLNN VROOO\n");
    }
    return 0;
}
