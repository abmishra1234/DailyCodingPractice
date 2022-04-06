#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<string>
#include<vector>

struct SearchAll
{

	vector<int> solve(string bigstring, string pattern) {
		vector<int> output;
		int ind = 0;
		int patLen = pattern.length();

		do {
			ind = bigstring.find(pattern, ind);
			if (ind != -1) {
				output.push_back(ind);
				ind += patLen;
			}
		} while (ind != -1);
		return output;
	}
};

// Driver code for verification of logic
int main() {

	string bigString = "I liked the movie, acting in movie was great!";
	string pattern = "movie";

	SearchAll sa;

	vector<int> result = sa.solve(bigString, pattern);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}
#endif // FORREF

