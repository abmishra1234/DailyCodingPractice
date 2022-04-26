/*
	Longest Band Problem
*/

#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<unordered_map>

typedef std::unordered_map<int, int> Map;
typedef Map::iterator MapIter;

struct LongBand {
	Map map;
	vector<bool> flags;

	LongBand(int n) : flags(n + 1, false) {}

	bool isExist(int val) {
		MapIter iter = map.find(val);
		if (iter != map.end()) {
			flags[iter->second] = true;
			return true;
		}
		return false;
	}

	int leftSideLen(int val, int minval) {
		--val;
		if (val < minval)
			return 0;

		int len = 0;
		while (val >= minval && isExist(val)) {
			++len;
			--val;
		}

		return len;
	}

	int rightSideLen(int val, int maxval) {
		++val;
		if (val > maxval)
			return 0;

		int len = 0;
		while (val <= maxval && isExist(val)) {
			++len;
			++val;
		}

		return len;
	}

	int solve(vector<int> arr) {
		int longest = INT_MIN;

		// use this flag array to check does this element is already verified?
		int minval = INT_MAX;
		int maxval = INT_MIN;

		// O(n), where n is the size of arr
		for (int i = 0; i < arr.size(); ++i) {
			map.insert(make_pair(arr[i], i));
			minval = min(arr[i], minval);
			maxval = max(arr[i], maxval);
		}

		for (int i = 0; i < arr.size(); ++i) {
			int llen = 0;
			if (flags[i] == false) {
				++llen;
				llen += leftSideLen(arr[i], minval);
				llen += rightSideLen(arr[i], maxval);
				longest = max(longest, llen);
			}
		}

		return longest;
	}

};

// driver code
int main() {
	vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
	LongBand lb(arr.size());
	cout << lb.solve(arr) << endl;
}



#endif // !FORREF

