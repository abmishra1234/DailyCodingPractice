/*
	Grid Problem #4
	Problem statement#
	Let’s discuss one more complex problem based on grids. 
	It is another variant of the grid problems that we discussed earlier. 
	The problem statement is given below. You are given a 2-D matrix 
	A of n rows and m columns where A[i][j] denotes the calories burnt. 
	Two persons, a boy and a girl start from two corners of this matrix. 
	The boy starts from the cell (1, 1) and needs to reach the cell (n, m). 
	On the other hand, the girl starts from the cell (n, 1) and needs to reach (1, m). 
	The boy can move right and down. The girl can move right and up. As they visit a cell, 
	the amount in the cell A[i][j] is added to their total of calories burnt. 
	You have to maximize the sum of total calories burnt by both of them under the condition 
	that they shall meet only in one cell and the cost of this cell shall not be included in 
	either of their totals.

	Solution : Dynamic Programming Approach

*/

#define FORREF
#ifndef FORREF

using namespace std;
#include<iostream>
#include<vector>

typedef vector<vector<int>> Memo;
const int NN = 1005;

struct MaxCalories {

	int solve(int rows, int cols, Memo &calarie) {

		Memo boy_start(NN, vector<int>(NN, 0));
		Memo boy_end(NN, vector<int>(NN, 0));
		Memo girl_start(NN, vector<int>(NN, 0));
		Memo girl_end(NN, vector<int>(NN, 0));

		// for making table of calorie for boy before meeting
		for (int i = 1; i <= rows; ++i) {
			for (int j = 1; j <= cols; ++j) {
				boy_start[i][j] = calarie[i - 1][j - 1] + max(boy_start[i - 1][j], boy_start[i][j - 1]);
			}
		}
		
		for (int i = rows; i > 0; --i) {
			for (int j = 1; j <= cols; ++j) {
				girl_start[i][j] = calarie[i - 1][j - 1] + max(girl_start[i + 1][j], girl_start[i][j - 1]);
			}
		}

		for (int i = rows; i >= 1; i--) {
			for (int j = cols; j >= 1; j--) {
				boy_end[i][j] = calarie[i-1][j-1] + max(boy_end[i + 1][j], boy_end[i][j + 1]);
			}
		}

		for (int i = 1; i <= rows; i++) {
			for (int j = cols; j >= 1; j--) {
				girl_end[i][j] = calarie[i-1][j-1] + max(girl_end[i - 1][j], girl_end[i][j + 1]);
			}
		}

		int ans = 0;
		for (int i = 2; i < rows; i++) {
			for (int j = 2; j < cols; j++) {
				int ans1 = boy_start[i][j - 1] + boy_end[i][j + 1] + girl_start[i + 1][j] + girl_end[i - 1][j];
				int ans2 = boy_start[i - 1][j] + boy_end[i + 1][j] + girl_start[i][j - 1] + girl_end[i][j + 1];
				ans = max(ans, max(ans1, ans2));
			}
		}
		return ans;
	}

};


// Driver code
int main() {
	int M = 3;
	int N = 3;

	MaxCalories mc;
	
	// fill the calaries of cell
	Memo calarie { {100,100,100},{100,1,100},{100,100,100} };
	cout << mc.solve(M, N, calarie) << endl;

	return 0;
}

#endif // !FORREF

