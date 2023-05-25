//by SURANJAN DAS
#include <stdio.h>

int max(int a,int b) {return a>b?a:b;};

// Recursive function to find the maximum value that can be obtained from the knapsack
int unboundedKnapsack(int values[], int weights[], int n, int capacity) {
    // Base case: if either the capacity becomes 0 or no items are left
    if (capacity == 0 || n == 0)
        return 0;

    // If the weight of the current item exceeds the capacity, skip it
    if (weights[n - 1] > capacity)
        return unboundedKnapsack(values, weights, n - 1, capacity);

    // Return the maximum of two cases:
    // 1. Include the current item and recursively call the function with the reduced capacity
    // 2. Exclude the current item and recursively call the function with the same capacity and next item
    return max(values[n - 1] + unboundedKnapsack(values, weights, n, capacity - weights[n - 1]),
               unboundedKnapsack(values, weights, n - 1, capacity));
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
