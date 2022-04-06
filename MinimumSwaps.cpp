/*
	Minimum Swaps required to sort the array
	It's little bit tricky problem
	Completed and There is definately Learning
	Attach the link of github pdf for understanding the problem
	link : TBD
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

typedef std::pair<int, int> Pair;

struct MinSwap {
	
	int solve(vector<int> arr) {
		int minswaps = 0;

		// minimum swap required to sort the given array
		vector<Pair> pairArr(arr.size());
		
		// Filled with pair for value and index
		for (int i = 0; i < arr.size(); ++i) {
			pairArr[i].first = arr[i];
			pairArr[i].second = i;
		}

		// Sort the pair array
		sort(pairArr.begin(), pairArr.end());
		
		// mark the visited index for detecting the cycle
		vector<bool> visited(arr.size() + 1, false);
		
		for (int i = 0; i < arr.size(); ++i) {
			// These are the cases where you don't have to do anything
			if (visited[i] || i == pairArr[i].second)
				continue;
			
			int nodes = 0;
			int index = i;
			while (!visited[index] && index != pairArr[index].second) {
				// than swap element
				visited[index] = true;
				++nodes;
				index = pairArr[index].second;
			}
			
			minswaps += (nodes - 1);
		}

		return minswaps;
	}
};

// Driver code
int main() {

	vector<int> arr{10,11,5,4,3,2,1};
	MinSwap ms;
	cout << "output = " << ms.solve(arr) << endl;

	return 0;
}




#endif // FORREF
