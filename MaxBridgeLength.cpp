/*
	Max Bridge is the use case for LIS
	How LIS is helping different interview problem solution based on his implementation.
*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
typedef vector<std::pair<int, int>> ListPair;

struct MaxBridges {

	int solve(ListPair points) {
		sort(points.begin(), points.end());

		int res = 0;
		int n = points.size();
		vector<int> lis(n, 1);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (points[i].second >= points[j].second and lis[i] < 1 + lis[j]) {
					lis[i] = lis[j] + 1;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (res < lis[i]) {
				res = lis[i];
			}
		}

		return res;
	}
};

int main() {
	ListPair points{ {5,4}, {8,1}, {2,6} , {10,2}, {12,3} };
	MaxBridges mb;
	cout << "Answer = " << mb.solve(points) << endl;

	return 0;
}

#endif // !FORREF
