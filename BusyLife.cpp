/*
	Busy Life Problem & Solution
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

// This is define for managing the activity{start time, end time}
typedef std::pair<int, int> Pair; 

// This is defined for collection of Activity
typedef vector<Pair> ActivityList; 

bool compare(Pair f, Pair s) {
	if (f.second < s.second)
		return true;
	return false;
}

struct CountActivity {
	
	int solve(ActivityList list) {
		int listSize = list.size();
		if (listSize <= 0)
			return 0;

		int count = 1;

		sort(list.begin(), list.end(), compare);
		for (int i = 1; i < list.size(); ++i) {
			if (list[i].first >= list[i - 1].second) {
				++count;
			}
		}
		return count;
	}

};

// Driver code
int main()
{
	ActivityList activities;
	activities.push_back(make_pair(7, 9));
	activities.push_back(make_pair(0, 10));
	activities.push_back(make_pair(4, 5));
	activities.push_back(make_pair(8, 9));
	activities.push_back(make_pair(4, 10));
	activities.push_back(make_pair(5, 7));

	CountActivity ca;
	cout << "Number of activity : " << ca.solve(activities) << endl;

	return 0;
}

#endif // !FORREF

