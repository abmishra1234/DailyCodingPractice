/*
	Tokenization kind of standard method using c++ concepts
	using this with stringstream class , included in #include<stream>
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

struct Tokenization {
	vector<string> solve(string str) {
		vector<string> result;
		stringstream buffer(str);
		string token;

		while (getline(buffer, token, ' ')) {
			result.push_back(token);
		}

		return result;
	}
};

// Driver Code
int main() {
	string str = "This is my learning and growing year with full focus on improvements!!!";
	Tokenization tk;

	vector<string> out = tk.solve(str);
	// print on screen
	for (int i = 0; i < out.size(); ++i) {
		cout << out[i] << endl;
	}

	return 0;
}

#endif // !FORREF
