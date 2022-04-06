/*
	Array Products

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<limits>
#include<unordered_map>

struct ArrayProiducts {
	/*
		Brute force
		- You are not suppose to use the divison operator

	*/
	vector<int> solve(vector<int> arr) {
		// To solve this problem efficiently, the concept of pre-computing is used
		vector<int> left(arr.size(), 1), right(arr.size(), 1);
		for (int i = 0; i < arr.size(); ++i) {
			if (i == 0) {
				left[i] = 1;
			}
			else
			{
				left[i] = left[i - 1] * arr[i - 1];
			}
		}

		for (int i = arr.size()-1; i >= 0; --i) {
			if (i == arr.size() - 1) {
				right[i] = 1;
			}
			else
			{
				right[i] = right[i + 1] * arr[i + 1];
			}
		}

		for (int i = 0; i < arr.size(); ++i) {
			arr[i] = left[i] * right[i];
		}
		return arr;
	}
};



// Driver code
int main() {
	vector<int> arr{ 1,2,3,4,5 };
	ArrayProiducts ap;
	vector<int> res = ap.solve(arr);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}


#endif // !FORREF


