/*
	Problem :
	Implement a function that takes an input a vector of integers, and points
	the maximum subarray sum that can be formed. A subarray is defined as consecutive
	segment of the array. If all numbers are negative, than return 0.
	
	Example 01:
	input : {-1, 2, 3, 4, -2, 6, -8, 3}
	output : 13

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct SubArraySum {
	/*
		The maximum sum of subarray possible from given input array.
		Please note that it has positive and negative both type of elements exists
	*/
	int solve_brut(vector<int> arr) {
		int maxsum = INT_MIN;
		for (size_t i = 0; i < arr.size(); ++i) {
			int lsum = 0;
			for (size_t j = i; j < arr.size(); ++j) {
				maxsum = max(maxsum, lsum += arr[j]);
			}
		}
		return maxsum;
	}

	/*
		Let's implement other better approach from O(n), O(1)
		Using Kadane algorithm

	*/
	int solve_kadanes(vector<int> arr) {
		int arrSize = arr.size();
		if (arrSize <= 0)
			return 0;

		int max_global = INT_MIN;
		int max_current = max_global = arr[0];

		for (int i = 1; i < arrSize; ++i) {
			max_current = max(arr[i], max_current + arr[i]);
			if (max_current > max_global) {
				max_global = max_current;
			}
		}
		return max_global;
	}
};


// Driver Code
int main() {

	vector<int> arr{ -1,2,3,4,-2,6,-8,3 };
	SubArraySum sa;

	cout <<"Brute Force : " <<  sa.solve_brut(arr) << endl;
	cout << "Kadane Algorithm : " << sa.solve_kadanes(arr) << endl;


	return 0;
}




#endif // !FORREF


