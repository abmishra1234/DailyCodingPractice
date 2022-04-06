/*
	Minimum Difference


*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

typedef std::pair<int, int> Pair;

struct MinDifference {
	Pair solve_brut(vector<int> arr1, vector<int> arr2) {
		/*
			Brute force approach
			Time complexity : O(n^2)
			Space complexity : O(1)
		*/
		Pair minDiffPair(0,0);
		int mindiff = INT_MAX;
		// So observing this solution, seems many sub problems overlapping in naturte so it
		// by chance you will able to avoid than you might solve this problem efficiently
		for (size_t i = 0; i < arr1.size(); ++i) {
			for (size_t j = 0; j < arr2.size(); ++j) {
				if (abs(arr1[i] - arr2[j]) < mindiff) {
					mindiff = abs(arr1[i] - arr2[j]);
					minDiffPair.first = arr1[i];
					minDiffPair.second = arr2[j];
				}
			}
		}

		return minDiffPair;
	}

	/*
		This is improved but still order (n^2)
		Also, you have sorted the array : O(nlogn)
	*/
	Pair solve_impr(vector<int> arr1, vector<int> arr2) {
		Pair minDiffPair(0, 0);
		int mindiff = INT_MAX;

		// sort both the array
		sort(arr1.begin(), arr1.end());
		sort(arr2.begin(), arr2.end());

		// So observing this solution, seems many sub problems overlapping in naturte so it
		// by chance you will able to avoid than you might solve this problem efficiently
		// This approach definately provide better result than earlier approach
		for (size_t i = 0; i < arr1.size(); ++i) {
			for (size_t j = 0; j < arr2.size(); ++j) {
				if (abs(arr1[i] - arr2[j]) < mindiff) {
					mindiff = abs(arr1[i] - arr2[j]);
					minDiffPair.first = arr1[i];
					minDiffPair.second = arr2[j];
				}
				else
					break;
			}
		}

		return minDiffPair;
	}

	/*
		This is better than brute force but still kind of O(n^2) only.
		So think , how you could make more better solution?
	*/








};




// Driver code
int main() {
	vector<int> arr1{23,5,10,17,30};
	vector<int> arr2{26,134,135,14,19};

	MinDifference md;
	Pair result = md.solve_brut(arr1, arr2);
	cout << result.first << ", " << result.second << endl;

	cout << "With some improvement in previous approach" << endl;
	result = md.solve_impr(arr1, arr2);
	cout << result.first << ", " << result.second << endl;




}

#endif // !FORREF


