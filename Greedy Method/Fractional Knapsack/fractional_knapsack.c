#include <stdio.h>
#include <stdlib.h>

// structure for items in the knapsack
struct Item {
    int value;
    int weight;
};

// compare function for sorting items by decreasing value-to-weight ratio
int cmp(const void *a, const void *b) {
    const struct Item *itemA = (const struct Item *) a;
    const struct Item *itemB = (const struct Item *) b;
    double ratioA = (double) itemA->value / itemA->weight;
    double ratioB = (double) itemB->value / itemB->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}

// function to solve the fractional knapsack problem
void fractionalKnapsack(struct Item items[], int n, int capacity, int *total_value, struct Item knapsack[]) {
    qsort(items, n, sizeof(struct Item), cmp);
    *total_value = 0;
    int knapsack_size = 0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            knapsack[knapsack_size++] = items[i];
            capacity -= items[i].weight;
            *total_value += items[i].value;
        } else {
            double fraction = (double) capacity / items[i].weight;
            knapsack[knapsack_size].value = fraction * items[i].value;
            knapsack[knapsack_size].weight = capacity;
            *total_value += knapsack[knapsack_size].value;
            break;
        }
    }
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    struct Item knapsack[n];
    int total_value;
    fractionalKnapsack(items, n, capacity, &total_value, knapsack);
    printf("Total value: %d\n", total_value);
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (knapsack[i].weight == 0) {
            break;
        }
        printf("- Item with value %d and weight %d\n", knapsack[i].value, knapsack[i].weight);
    }
    return 0;
}
