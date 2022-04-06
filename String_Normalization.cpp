/*
	Problem for string normalization
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct StringNormalize {
	// If you want more supporting methods to be used inside the function
	/*
		Define one utility method for identifying the character is small case or capital case 
		or a symbol
		small case - 0
		capital case  - 1
		symbol - 2
	*/

	int IdentifyChar(char ch) {
		int type = 2;
		if (ch >= 'a' and ch <= 'z') {
			type = 0;
		}
		else if (ch >= 'A' and ch <= 'Z') {
			type = 1;
		}
		return type;
	}



	string Normailze(string sentence) {
		string copy = sentence;
		int lcopy = copy.length();
		bool capital = true;

		for (int i = 0; i < lcopy; ++i) {
			if (copy[i] == ' ') {
				capital = true;
				continue;
			}

			int res = IdentifyChar(copy[i]);
			if (res == 0 && capital) {
				copy[i] = 'A' + (copy[i] - 'a');
				capital = false;
			}
			else if (res == 1) {
				if (capital) {
					capital = false;
				}
				else
					copy[i] = 'a' + (copy[i] - 'A');
			}
		}

		return copy;
	}
};

// Driver Code
int main() {
	StringNormalize sn;
	cout << sn.Normailze("This is SO MUCH FUN!") << endl;



	return 0;
}

#endif // !FORREF