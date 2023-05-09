/*
1. Create a priority queue (Min-Heap) and push the activities into it.
2. Push the top of the priority queue into the answer vector and set the variable start to the start time of the first activity and end to the finish time of the activity
3. While priority is not empty do the following:
        Take the top of the priority queue and check
        If the start time of this activity is greater than or equal to the finish time of the last chosen activity then push this activity into the answer vector
        Else ignore it
4. Print the activities chosen, stored in the answer vector
*/

//by SURANJAN DAS
#include <bits/stdc++.h>
using namespace std;

void SelectActivities(vector<int> s, vector<int> f)
{
	// Vector to store results.
	vector<pair<int, int> > ans;

	// Minimum Priority Queue to sort activities in
	// ascending order of finishing time (f[i]).

	priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int> > > p;

	for (int i = 0; i < s.size(); i++) {
		// Pushing elements in priority queue where the key is f[i]
		p.push(make_pair(f[i], s[i]));
	}

	auto it = p.top();
	int start = it.second;
	int end = it.first;
	p.pop();
	ans.push_back(make_pair(start, end));

	while (!p.empty()) {
		auto itr = p.top();
		p.pop();
		if (itr.second >= end) {
			start = itr.second;
			end = itr.first;
			ans.push_back(make_pair(start, end));
		}
	}
	cout << "Following Activities should be selected. "
		<< endl
		<< endl;

	for (auto itr = ans.begin(); itr != ans.end(); itr++) {
		cout << "Start time= " << (*itr).first<< " and end time = " << (*itr).second << endl;
	}
}

// Driver code
int main()
{
	vector<int> s = { 1, 3, 0, 5, 8, 5 };
	vector<int> f = { 2, 4, 6, 7, 9, 9 };

	// Function call
	SelectActivities(s, f);

	return 0;
}
