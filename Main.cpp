#pragma once

#define FORREF
#ifndef FORREF


using namespace std;
#include <iostream>
#include<vector>

extern int LIS(vector<int> arr);
extern void print_lis(vector<int> arr);

int main() {
	vector<int> arr{ 10,9,3,5,4,11,7,8 };
	print_lis(arr);

	return 0;
}
#endif // !FORREF

