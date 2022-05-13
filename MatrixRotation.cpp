/*
	Matrix Operation...

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include <iostream>
#include<vector>

#define MAX_R 100
#define MAX_C 100

typedef vector<vector<int>> Matrix; // here, Matrix is two dimensional array representation
Matrix mat(MAX_R, vector<int>(MAX_C, 0));

struct MatrixOperation {
	// Set the actual value of nR and nC
	int R, C;

	// constructor for setting data into the matrix
	MatrixOperation(int nR, int nC, int data[MAX_R][MAX_C]) {
		R = nR;
		C = nC;

		for (int i = 0; i < nR; ++i) {
			for (int j = 0; j < nC; ++j) {
				mat[i][j] = data[i][j];
			}
		}
	}
	// Print the matrix value for verification
	void printMat() {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	// Let's define the transpose method
	void transpose() {
		// make rows to column
		int nR = C;
		int nC = R;
		Matrix nmat(MAX_R, vector<int>(MAX_C, 0));

		for (int r = 0; r < R; ++r) {
			for (int c = 0, c2 = r; c < C; ++c) {
				nmat[c][c2] = mat[r][c];
			}
		}

		for (int r = 0; r < nR; ++r) {
			for (int c = 0; c < nC; ++c) {
				mat[r][c] = nmat[r][c];
			}
		}

		R = nR; 
		C = nC;
	}

	void swapCols() {
		for (int r = 0; r < R; ++r) {
			for (int c = 0, cr = C - 1; c < cr; ++c, --cr) {
				swap(mat[r][c], mat[r][cr]);
			}
		}
	}





};




int main() {

	int arr[MAX_R][MAX_C] = { {1,2,3}, {4,5,6} };
	MatrixOperation mo(2,3, arr);
	mo.printMat();

	// 1
	cout << "rotate 90->" << endl;
	mo.transpose();
	mo.swapCols();
	mo.printMat();
	// 2 
	cout << "rotate 180->" << endl;
	mo.transpose();
	mo.swapCols();
	mo.printMat();

	// 3
	cout << "rotate 270->" << endl;
	mo.transpose();
	mo.swapCols();
	mo.printMat();






	return 0;
}








#endif // !FORREF
