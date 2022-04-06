/*
	Maximise the Unique Substring from Given String as an input
	Tag << Sliding Window >>

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include "unordered_map"

typedef std::unordered_map<char, int> CharVsIndexMap;
typedef CharVsIndexMap::iterator MapIter;

// for managing the two pointer over the string for making substring 
typedef std::pair<int, int> Pair;
typedef vector<Pair> PairVect;

struct LongestUniqueSubstring {
	/*
		your task is to find the unique substring in given string and return the
		longest such substring by following constraint of uniqueness
		I have to implement one method here
	*/

	string solve(string str) {
		string output = ""; // assign some empty string
		Pair range; // This is the range for managing the longest substring as your final answer

		int i = 0; // start mark for your substring
		int j = 0; // end mark for your substring

		CharVsIndexMap map;
		MapIter iter;
		int len = 0;
		int maxlen = 0;


		for (; j < str.length();) {
			iter = map.find(str[j]);
			if (iter == map.end()) {
				// meaning not exist in map
				map.insert(make_pair(str[j], j));
				++j;
			}
			else {
				/* this is the condition where we found that our current char is already in mapand so if you consider this than your uniqueness constraint will go for toss,
					so what would be the best option for us at this moment, we can consider the length of substring for now and check does this is providing any output better than what you have
					until now? in terms of length of substring ?
					If your answer is yes than you just have to consider this string for longest string you received until now and update the pair for the character and continue forward...

					repeat until you iterated all the character in the given string at least once.
				*/
				len = j - i;
				if (len > maxlen) {
					range.first = i;
					range.second = j-1;
					maxlen = len;
				}
				// update the start range for new substring exploration
				i = iter->second + 1;

				// map index update
				iter->second = j;

				++j;
			}

			// you should plan here is like, imagine if you have just got all the elements unique in your string
			// than max length will be not updated earlier because there is no repeating call
			if (j == str.length() - 1) {
				len = (j - i);
				if (len > maxlen) {
					range.first = i;
					range.second = j;
					maxlen = len;
				}
			}
		}
		return output = str.substr(range.first, range.second + 1);
	}

};

// Driver code for verifying the logic
int main() {
	LongestUniqueSubstring lus;
	string str{"abcdefgh"};
	cout << lus.solve(str) << endl;
	str = "abcdabef";
	cout << lus.solve(str) << endl;
	str = "abinash";
	cout << lus.solve(str) << endl;
	str = "aaaaaaaa";
	cout << lus.solve(str) << endl;

	return 0;
}


#endif // !FORREF


