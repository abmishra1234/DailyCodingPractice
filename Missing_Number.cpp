/*
	Find missing number 
	Amazon Interview Problem
*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct MissingNum {

	// Approach 01
	int solve_approach01(vector<int> &arr) {
		int sum = 0;
		for (auto elem : arr) {
			sum += elem;
		}

		// sum of first n natural number
		int s = arr.size();
		int mis_num = ((s + 1) * (s + 2)) / 2 - sum;
		return mis_num;
	}

	// Approach 02 : XOR approach
	int solve_approach02(vector<int>& arr) {
		int sum01 = 0;
		for (int elem : arr) {
			sum01 ^= elem;
		}

		int sum02 = 0;
		for (int i = 1; i <= arr.size() + 1; ++i) {
			sum02 ^= i;
		}

		return sum01 ^ sum02;
	}

	// Approach 03
	int solve_approach03(vector<int>& arr) {
		int n = arr.size();
		arr.push_back(-1);
		arr.push_back(-1);

		for (int i = 0; i < arr.size();) {
			if (i == arr[i] || arr[i] == -1) {
				++i;
				continue;
			}
			else if (i != arr[i] && arr[i] != -1) {
				// swap the element
				int temp = arr[i];
				arr[i] = arr[arr[i]];
				arr[temp] = temp;
			}
		}

		int missing = -1;

		for (int i = 1; i <= n + 1; ++i) {
			if (-1 == arr[i]) {
				missing = i;
			}
		}
		return missing;
	}

};

// Driver code
int main() {
	MissingNum mn;

	vector<int> arr { 1, 2, 4, 5, 6 };
	int miss = mn.solve_approach01(arr);
	cout << "The missing number is : " << miss << endl;

	int miss2 = mn.solve_approach02(arr);
	cout << "Approach 02 -> The missing number is : " << miss2 << endl;

	int miss3 = mn.solve_approach03(arr);
	cout << "Approach 03 -> The missing number is : " << miss3 << endl;


	return 0;
}

#endif // !FORREF

