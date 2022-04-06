#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<strstream>

// This step is crucial 
bool compare(string s1, string s2) {
	return s1+s2 > s2+s1;
}

struct Concatenate {

	string solve(vector<int> arr) {
		vector<string> strarr;
		
		for (size_t i = 0; i < arr.size(); ++i) {
			strarr.push_back(std::to_string(arr[i]));
		}

		sort(strarr.begin(), strarr.end(), compare);
		string result = "";
		for (size_t i = 0; i < strarr.size(); ++i) {
			result += strarr[i];
		}

		return result;
	}
};

// Driver code
int main() {
	vector<int> arr{10, 11, 20, 30, 3};
	Concatenate cc;
	cout << cc.solve(arr) << endl;

	return 0;
}


#endif // !FORREF


