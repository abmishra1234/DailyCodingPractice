/*
	Rain water trapping problem
*/

 #define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct Rains {
	int trappedWater(vector<int> heights) {
		int totalWater = 0;
		
		// Step 01
		// collect maximum building height from left
		vector<int> left(heights.size(), 0);
		int lmax = INT_MIN;
		for (int i = 0; i < left.size(); ++i) {
			lmax = left[i] = max(lmax, heights[i]);
		}

		vector<int> right(heights.size(), 0);
		lmax = INT_MIN;
		for (int i = left.size()-1; i >= 0; --i) {
			lmax = right[i] = max(lmax, heights[i]);
		}

		// Step 02
		for (int i = 1; i < heights.size(); ++i) {
			totalWater += min(left[i], right[i]) - heights[i];
		}

		return totalWater;
	}
};

// Driver code
int main() {
	vector<int> water{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	Rains rs;
	cout << " Total water trapped during rain is " << rs.trappedWater(water) << endl;
}

#endif // !FORREF

