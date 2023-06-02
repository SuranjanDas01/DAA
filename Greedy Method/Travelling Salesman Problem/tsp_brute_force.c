//by SURANJAN DAS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

// Function to calculate the distance between two cities
int calculateDistance(int cities[MAX_CITIES][MAX_CITIES], int city1, int city2) {
    return cities[city1][city2];
}

// Function to find the minimum distance using brute force
int tspBruteForce(int cities[MAX_CITIES][MAX_CITIES], int numCities) {
    int *path = malloc(numCities * sizeof(int));
    int *minPath = malloc(numCities * sizeof(int));
    int minDistance = INT_MAX;
    
    // Generate initial path
    for (int i = 0; i < numCities; i++) {
        path[i] = i;
    }
    
    // Find minimum path
    do {
        int currentDistance = 0;
        
        // Calculate total distance for the current path
        for (int i = 0; i < numCities - 1; i++) {
            currentDistance += calculateDistance(cities, path[i], path[i + 1]);
        }
        
        // Add distance from the last city back to the starting city
        currentDistance += calculateDistance(cities, path[numCities - 1], path[0]);
        
        // Update minimum distance and path if necessary
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            for (int i = 0; i < numCities; i++) {
                minPath[i] = path[i];
            }
        }
        
    } while (next_permutation(path, numCities));
    
    // Print the minimum path
    printf("Minimum Path: ");
    for (int i = 0; i < numCities; i++) {
        printf("%d ", minPath[i]);
    }
    
    printf("\nMinimum Distance: %d\n", minDistance);
    
    free(path);
    free(minPath);
    
    return minDistance;
}

// Function to generate the next permutation
int next_permutation(int *path, int numCities) {
    int i = numCities - 1;
    
    while (i > 0 && path[i - 1] >= path[i]) {
        i--;
    }
    
    if (i <= 0) {
        return 0;
    }
    
    int j = numCities - 1;
    
    while (path[j] <= path[i - 1]) {
        j--;
    }
    
    int temp = path[i - 1];
    path[i - 1] = path[j];
    path[j] = temp;
    
    j = numCities - 1;
    
    while (i < j) {
        temp = path[i];
        path[i] = path[j];
        path[j] = temp;
        i++;
        j--;
    }
    
    return 1;
}

int main() {
    // Define the cities and their distances
    int cities[MAX_CITIES][MAX_CITIES] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int numCities = 4; // Number of cities
    
    // Solve TSP using brute force
    tspBruteForce(cities, numCities);
    
    return 0;
}
