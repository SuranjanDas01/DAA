//By SURANJAN DAS
//Returns true or false for a particular N
#include <stdio.h>
#include <stdbool.h>

#define N 4 // Number of queens and board size

int board[N][N];

// Function to check if a queen can be placed in the given position
bool canPlace(int row, int col) {
    int i, j;

    // Check for queens in the same column
    for (i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check for queens in the upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check for queens in the upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int row) {
    // Base case: If all queens are placed, return true
    if (row == N) {
        return true;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (canPlace(row, col)) {
            // Place the queen in the current position
            board[row][col] = 1;

            // Recursively solve for the next row
            if (solveNQueens(row + 1))
                return true;

            // If placing the queen doesn't lead to a solution, backtrack and remove the queen
            board[row][col] = 0;
        }
    }

    // If no column allows placing the queen, return false
    return false;
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", (board[i][j] == 1) ? 'Q' : '-');
        }
        printf("\n");
    }
}

int main() {
    // Initialize the board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the N-Queens problem
    if (solveNQueens(0)) {
        printf("Solution:\n");
        printBoard();
    } else {
        printf("No solution exists for N = %d.\n", N);
    }

    return 0;
}
