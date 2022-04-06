#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct NumWays {

	int solve(int r, int c) {
		vector<vector<int>> dp(r, vector<int>(c, 0));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (i == 0 and j == 0) {
					dp[i][j] = 1;
				}
				else if (i == 0) {
					dp[0][j] = 1;
				}
				else if (j == 0) {
					dp[i][0] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[r-1][c-1];
	}
};



// Drive code for the handling of Grid problem using DP
int main() {
	NumWays nw;
	cout << nw.solve(3, 3) << endl;
	return 0;
}

#endif // FORREF