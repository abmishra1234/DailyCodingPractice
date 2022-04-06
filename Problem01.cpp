/*
	Problem : 
	Given an array, find the average of all subarrays of ‘K’ contiguous 
	elements in it.	
*/
#define FORREF
#ifndef FORREF

using namespace std;
#include<iostream>
#include<vector>

struct AvgSumWnd {
	/*
		arr : your array of integeres
		K is your window size
	*/
	vector<double> AvgSum(vector<int> arr, int K) {
		vector<double> result;
		int s = arr.size();
		int sum = 0;
		bool windowSum = false;

		if (s < K) {
			for (auto i : arr) {
				sum += i;
			}
			result.push_back((double)sum / K);
		}
		else
		{
			for (int i = 0; i <= arr.size() - K; ++i) {
				if (sum == 0) {
					// There is something to be added
					for (int j = 0; j < K; ++j) {
						sum += arr[j + i];
					}
				}
				else
				{
					sum -= arr[i-1];
					sum += arr[i + K-1];
				}
				result.push_back((double)sum / K);
			}
		}

		return result;
	}
};

// Driver code
int main() {
	vector<int> arr{ 1, 3, 2, 6, -1, 4, 1, 8, 2 };
	int K = 5;

	AvgSumWnd inst;
	vector<double> ans = inst.AvgSum(arr, K);

	// I will just print the average sum as an output below
	cout << "[";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i == ans.size() - 1) {
			cout << "";
		}
		else
			cout << ", ";
	}
	cout << "]";
	cout << endl;

	return 0;
}

#endif // !FORREF
