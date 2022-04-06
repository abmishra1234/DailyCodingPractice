#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct MinCost {

	int solve(int cost[3][3], int row, int col) {
		vector<vector<int>> dp(row, vector<int>(col, 0));

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (i == 0 and j == 0) {
					// this is the same cost required to be inside this cell
					dp[i][j] = cost[0][0]; 
				}
				else if (i == 0) {
					// means if you are in zeroth row
					dp[i][j] = cost[i][j] + dp[i][j - 1];
				}
				else if (j == 0) {
					// means if you are in zeroth col
					dp[i][j] = cost[i][j] + dp[i - 1][j];
				}
				else
				{
					dp[i][j] = cost[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}

		return dp[row - 1][col - 1];
	}

};

// Driver code 
int main() {
	int cost[3][3] = {
		{1,2,3},
		{4,8,2},
		{1,5,3}
	};

	int dest_r = 2;
	int dest_c = 2;

	MinCost mc;
	cout << mc.solve(cost, dest_r, dest_c) << endl;

	return 0;
}


#endif // !FORREF
