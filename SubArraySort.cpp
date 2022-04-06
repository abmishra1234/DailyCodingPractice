/*
	Sub Array Sort Problem
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

typedef std::pair<int, int> Pair;

struct SubArray {
	Pair sort(vector<int> arr) {
		Pair pair = make_pair(-1, -1);
		if (arr.size() <= 2)
			return pair;

		// Find the Peek and valley into the array
		vector<int> peeks;

		for (size_t i = 1; i < arr.size() - 1; ++i) {
			if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i] ) {
				peeks.push_back(i);
			}
		}

		if (peeks.size() > 0) {
			// means your given series is is increasing order
			int len = 0;
			for (int i = 0; i < peeks.size(); ++i) {
				int peek_ind = peeks[i];
				
				while (peek_ind < arr.size()-1 && arr[peeks[i]] > arr[peek_ind+1]) {
					++len;
					++peek_ind;
				}
				pair.first = peeks[i];
				pair.second = peeks[i] + len;
				return pair;
			}
		}
		
		// do the same implementation for valley


		return pair;
	}

};

// Driver code

int main() {

	// Sample input
	vector<int> arr{1,2,3,4,5,8,6,7,9,10,11};
	SubArray sa;
	Pair pair = sa.sort(arr);
	cout << pair.first << " , " << pair.second << endl;

	// sample coutput [5,7]



}


#endif // !FORREF


