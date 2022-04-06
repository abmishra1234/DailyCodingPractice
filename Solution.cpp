using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

int LIS(vector<int> arr, vector<int> &lis)
{
	for (size_t i = 1; i < lis.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] and lis[i] < 1 + lis[j]) {
				lis[i] = 1 + lis[j];
			}
		}
	}
	
	int res = 0;
	for (int i = 0; i < lis.size(); ++i) {
		if (res < lis[i]) {
			res = lis[i];
		}
	}

	return res;
}


void print_lis(vector<int> arr)
{
	vector<int> lis(arr.size(), 1); // O(n)
	int cur_lis = LIS(arr, lis);

	// this is the list of longest Increasing subsequence from the given list
	vector<int> result;
	int prev = INT_MAX;

	for (int i = arr.size() - 1; i >= 0; --i) {
		if (cur_lis == lis[i] && arr[i] <= prev) {
			--cur_lis;
			result.push_back(arr[i]);
		}
		if (cur_lis == 0)
			break;
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
	cout << endl;

}
