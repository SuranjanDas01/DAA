//by SURANJAN DAS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 10

// Function to calculate the distance between two cities
int calculateDistance(int cities[MAX_CITIES][MAX_CITIES], int city1, int city2) {
    return cities[city1][city2];
}

// Function to find the nearest unvisited city
int findNearestCity(int cities[MAX_CITIES][MAX_CITIES], bool visited[MAX_CITIES], int currentCity, int numCities) {
    int nearestCity = -1;
    int minDistance = INT_MAX;
    
    for (int i = 0; i < numCities; i++) {
        if (!visited[i] && cities[currentCity][i] < minDistance) {
            minDistance = cities[currentCity][i];
            nearestCity = i;
        }
    }
    
    return nearestCity;
}

// Function to solve TSP using greedy approach
int tspGreedy(int cities[MAX_CITIES][MAX_CITIES], int numCities) {
    bool visited[MAX_CITIES] = {false};
    int *path = malloc(numCities * sizeof(int));
    int currentCity = 0;
    int totalDistance = 0;
    
    visited[currentCity] = true;
    path[0] = currentCity;
    
    for (int i = 1; i < numCities; i++) {
        int nearestCity = findNearestCity(cities, visited, currentCity, numCities);
        
        visited[nearestCity] = true;
        path[i] = nearestCity;
        
        totalDistance += calculateDistance(cities, currentCity, nearestCity);
        currentCity = nearestCity;
    }
    
    // Add distance from the last city back to the starting city
    totalDistance += calculateDistance(cities, currentCity, 0);
    
    // Print the path
    printf("Path: ");
    for (int i = 0; i < numCities; i++) {
        printf("%d ", path[i]);
    }
    
    printf("\nTotal Distance: %d\n", totalDistance);
    
    free(path);
    
    return totalDistance;
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
    
    // Solve TSP using greedy approach
    tspGreedy(cities, numCities);
    
    return 0;
}
