/*
	TBD
	It is purely implementation practice
	we will complete this later, for now just moving to Coding Exercise

*/


#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

typedef vector<string> TestInput;




/*
	Sample Input
	-------------------------
	3
	92 022
	82 12
	77 13
	2 false numeric
*/


// Driver Code
int main() {
	// read input 
	int count = 3;

	TestInput input(count + 1);
	input[0] = "92 022";
	input[1] = "82 12"; 
	input[2] = "77 13";

	
	

	return 0;
}

#endif // !FORREF