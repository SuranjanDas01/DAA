//by SURANJAN DAS
#include <bits/stdc++.h>
using namespace std;

// Structure to store the profit and weight of an item together
struct Item {
	int profit, weight;

	// Constructor
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

//Comparison function for sorting 
static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item items[], int N)
{
	// Sorting Item on basis of profit to weight ratio
	sort(items, items + N, cmp);

	double total_profit = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {
		
		// If adding Item won't overflow,
		// add it completely
		if (items[i].weight <= W) {
			W -= items[i].weight;
			total_profit += items[i].profit;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
            double fraction=((double)W / (double)items[i].weight);
			total_profit += items[i].profit* fraction;
			break;
		}
	}

	// Returning final value
	return total_profit;
}

int main()
{
	int W = 50;
	Item items[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int N = sizeof(items) / sizeof(items[0]);

	// Function call
	cout << "Total profit = "<<fractionalKnapsack(W, items, N)<<endl;
	return 0;
}
