#include <stdio.h>
#include <stdlib.h>



// Function to compare two items based on their size (used for sorting)
int compareItems(const void* a, const void* b) {
    int* itemA = (int*)a;
    int* itemB = (int*)b;
    return (*itemB)-(*itemA);
}

// Recursive function to solve the bin packing problem
int binPackingRecursive(int* items, int n, int binCapacity) {
    // Base case: If there are no items left, return 0
    if (n <= 0)
        return 0;
    if(n==1) return 1;
    // Divide items into two halves
    int mid = n / 2;
    int* firstHalf = items;
    int* secondHalf = items + mid;

    // Recursive calls to fit each half into bins
    int binsForFirstHalf = binPackingRecursive(firstHalf, mid, binCapacity);
    int binsForSecondHalf = binPackingRecursive(secondHalf, n - mid, binCapacity);

    // Merge the results and choose the minimum number of bins
    int binsForBothHalves = binsForFirstHalf + binsForSecondHalf;

    // Try to fit the items from the second half into remaining space in bins of the first half
    int remainingCapacity = binCapacity;
    int binsForMerged = 0;
    for (int i = mid; i < n; i++) {
        if (secondHalf[i] <= remainingCapacity) {
            remainingCapacity -= secondHalf[i];
        }
        else {
            binsForMerged++;
            remainingCapacity = binCapacity - secondHalf[i];
        }
    }

    return (binsForBothHalves < binsForMerged) ? binsForBothHalves : binsForMerged;
}

// Function to solve the bin packing problem using the divide and conquer approach
int binPacking(int* items, int n, int binCapacity) {
    // Sort items in descending order by size
    qsort(items, n, sizeof(int), compareItems);

    // Call the recursive helper function
    return binPackingRecursive(items, n, binCapacity);
}

int main() {
    int n, binCapacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of each bin: ");
    scanf("%d", &binCapacity);

    int* items = (int*)malloc(n * sizeof(int));

    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    int minBins = binPacking(items, n, binCapacity);

    printf("Minimum number of bins required: %d\n", minBins);

    // free(items);

    return 0;
}
