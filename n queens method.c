#include <stdio.h>
#include <stdbool.h>

#define N 8 // size of chessboard

// function to print the chessboard
void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a queen can be placed at (row, col)
bool is_safe(int board[N][N], int row, int col) {
    // check if there is a queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    // check if there is a queen in the upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    // check if there is a queen in the lower diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

// recursive function to solve the N Queens Problem
bool solve_n_queens(int board[N][N], int col) {
    // base case: all queens are placed
    if (col == N) {
        return true;
    }
    // try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;
            // recursively solve for the next column
            if (solve_n_queens(board, col+1)) {
                return true;
            }
            // backtrack: remove the queen from the current cell
            board[i][col] = 0;
        }
    }
    // no solution found
    return false;
}

int main() {
    int board[N][N] = {0};
    if (solve_n_queens(board, 0)) {
        printf("Solution found:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}
