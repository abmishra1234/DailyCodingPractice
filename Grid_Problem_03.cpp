/*
	DP problem for Grid structure and your task is to find the number of ways 
	to reach the destination.
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include <iostream>
#include<vector>

typedef vector<vector<int>> Memo;

struct NWays {
	int solve(int row, int col, Memo& dp) {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (i == 0 && j == 0) {
					dp[0][0] = (dp[0][0]) == -1 ? 0 : 1;
				}
				else if (i == 0) {
					// top row, and so the way from top is 0 and way from left is what final contribution is
					dp[0][j] = (dp[0][j] == -1) ? dp[0][j] : dp[0][j - 1];
				}
				else if (j == 0) {
					// left most col, means no way from left, only from top
					dp[i][0] = (dp[i][0] == -1) ? dp[i][0] : dp[i-1][0];
				}
				else
				{
					if (dp[i - 1][j] == -1 and dp[i][j - 1] == -1) {
						dp[i][j] = dp[i][j];
					}
					else if (dp[i - 1][j] == -1) {
						dp[i][j] = (dp[i][j] == -1) ? dp[i][j] : dp[i][j - 1];
					}
					else if (dp[i][j-1] == -1) {
						dp[i][j] = (dp[i][j] == -1) ? dp[i][j] : dp[i-1][j];
					}
					else {
						dp[i][j] = (dp[i][j] == -1) ? dp[i][j] : (dp[i - 1][j] + dp[i][j - 1]);
					}
				}
			}
		}
		return dp[row - 1][col - 1];
	}
};

// Driver Code
int main() {
	const int n = 4;
	const int m = 3;
	const int p = 2;

	int obstacles[p][p] = { {3,3}, {3,1} };
	Memo dp(n, vector<int>(m, 0));

	for (int i = 0; i < p; ++i) {
		dp[obstacles[i][0]-1][obstacles[i][1]-1] = -1;
	}

	NWays nw;
	cout << nw.solve(n, m, dp) << endl;

	return 0;
}

#endif // !FORREF

