//by SURANJAN DAS
//Time Complexity: O(N(logN)^2)
// A divide and conquer program in C/C++ to find the smallest euclideanDistanceance from a
// given set of points.

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// A structure to represent a Point in 2D plane
struct Point
{
	int x, y;
};

// Needed to sort array of points according to X coordinate
int compX(const void* a, const void* b)
{
	struct Point *p1 = (struct Point *)a, *p2 = (struct Point *)b;
	return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compY(const void* a, const void* b)
{
	struct Point *p1 = (struct Point *)a, *p2 = (struct Point *)b;
	return (p1->y - p2->y);
}

// A utility function to find the distance between two points
float euclideanDistance(struct Point p1,struct Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
			);
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce(struct Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (euclideanDistance(P[i], P[j]) < min)
				min = euclideanDistance(P[i], P[j]);
	return min;
}

// A utility function to find a minimum of two float values
float minimum(float x, float y)
{
	return (x < y)? x : y;
}


// A utility function to find the distance between the closest points of
// strip of a given size. All points in strip[] are sorted according to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float findStripClosest(struct Point strip[], int size, float d)
{
	float min = d; // Initialize the minimum distance as d

	qsort(strip, size, sizeof(struct Point), compY);

	// Pick all points one by one and try the next points till the difference
	// between y coordinates is smaller than d.
	// This is a proven fact that this loop runs at most 6 times
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (euclideanDistance(strip[i],strip[j]) < min)
				min = euclideanDistance(strip[i], strip[j]);

	return min;
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
float findClosest(struct Point P[], int n)
{
	// If there are 2 or 3 points, then use brute force
	if (n <= 3)
		return bruteForce(P, n);

	// Find the middle point
	int mid = n/2;
	struct Point midPoint = P[mid];

	// Consider the vertical line passing through the middle point
	// calculate the smallest euclideanDistanceance dl on left of middle point and
	// dr on right side
	float dl = findClosest(P, mid);
	float dr = findClosest(P + mid, n-mid);

	// Find the smaller of two euclideanDistanceances
	float d = minimum(dl, dr);

	// Build an array strip[] that contains points close (closer than d)
	// to the line passing through the middle point
	struct Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;

	// Find the closest points in strip. Return the minimum of d and closest
	// distance is strip[]
	return minimum(d, findStripClosest(strip, j, d) );
}

// The main function that finds the smallest distance
// This method mainly uses findClosest()
float closestPairOfPoints(struct Point P[], int n)
{
	qsort(P, n, sizeof(struct Point), compX);

	// Use recursive function findClosest() to find the smallest distance
	return findClosest(P, n);
}

// Driver program to test above functions
int main()
{
	struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P) / sizeof(P[0]);
	printf("The smallest distance is %f ", closestPairOfPoints(P, n));
	return 0;
}
