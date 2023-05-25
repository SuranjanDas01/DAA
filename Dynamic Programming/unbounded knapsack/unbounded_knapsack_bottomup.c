//by SURANJAN DAS
#include <stdio.h>

int max(int a,int b) {return a>b?a:b;};

// Function to find the maximum value that can be obtained from the knapsack
int unboundedKnapsack(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][capacity];
}

int main() {
    int values[] = {10, 30, 20};
    int weights[] = {5, 10, 15};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 100;

    int maxValue = unboundedKnapsack(values, weights, n, capacity);
    printf("Maximum value: %d\n", maxValue);

    return 0;
}
