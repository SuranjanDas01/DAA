//by SURANJAN DAS
///returns all answers for a given N
#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10 // Maximum board size

int board[MAX_N][MAX_N];
int solutions[MAX_N * MAX_N][MAX_N][MAX_N];
int numSolutions = 0;
int N;

// Function to check if a queen can be placed in the given position
bool canPlace(int row, int col) {
    int i, j;

    // Check for queens in the same column
    for (i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check for queens in the upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check for queens in the lower diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
void solveNQueens(int row) {
    // Base case: If all queens are placed, store the solution and return
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                solutions[numSolutions][i][j] = board[i][j];
            }
        }
        numSolutions++;
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (canPlace(row, col)) {
            // Place the queen in the current position
            board[row][col] = 1;

            // Recursively solve for the next row
            solveNQueens(row + 1);

            // Backtrack and remove the queen
            board[row][col] = 0;
        }
    }
}

// Function to print a single solution
void printBoard(int solutionIndex) {
    printf("Solution %d:\n", solutionIndex + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", (solutions[solutionIndex][i][j] == 1) ? 'Q' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Get the board size from the user
    printf("Enter the board size (N): ");
    scanf("%d", &N);

    if (N <= 0 || N > MAX_N) {
        printf("Invalid board size. Please enter a value between 1 and %d.\n", MAX_N);
        return 0;
    }

    // Initialize the board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the N-Queens problem
    solveNQueens(0);

    // Print all solutions
    if (numSolutions > 0) {
        printf("All solutions:\n");
        for (int i = 0; i < numSolutions; i++) {
            printBoard(i);
        }
    } else {
        printf("No solution exists for N = %d.\n", N);
    }

    return 0;
}
