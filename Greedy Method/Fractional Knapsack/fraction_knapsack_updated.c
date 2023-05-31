//by SURANJAN DAS
#include <stdio.h>
#include <stdlib.h>

// structure for items in the knapsack
struct Item {
    int value;
    int weight;
};

//sorting function
void sort(struct Item items[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double ratioA=items[i].value/items[i].weight;
            double ratioB=items[j].value/items[j].weight;
            if(ratioB>ratioA){
                double temp=items[i].value;
                items[i].value=items[j].value;
                items[j].value=temp;

                temp=items[i].weight;
                items[i].weight=items[j].weight;
                items[j].weight=temp;
            }
        }
    }
}

// function to solve the fractional knapsack problem
void fractionalKnapsack(struct Item items[], int n, int capacity, int *total_value, struct Item knapsack[]) {
    sort(items, n);
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
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30},{140,20}};
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
