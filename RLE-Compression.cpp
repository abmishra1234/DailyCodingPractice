/*
	RLE COmpression Implementation 
*/
#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


typedef unordered_map<int, int> CharMap;
typedef CharMap::iterator CharMapIter;

struct RLE {

	string Compression(string str) {
		string result = "";
		// Do we have any thing duplicate in your input?
		// if yes, than we will see the compression and their after verify the length with origional length
		// if no , no duplicate than it is sure that you have to just return the orioonal string
		CharMap map;
		CharMapIter iter;

		for (int i = 0; i < str.length(); ++i) {
			iter = map.find(str[i]);
			if (iter == map.end()) {
				map.insert(make_pair(str[i], 1));
			}
			else
				map[str[i]] += 1;
		}

		bool duplicate = false;
		iter = map.begin();
		while (iter != map.end()) {
			if (iter->second > 1 && !duplicate) {
				duplicate = true;
			}
			result += iter->first;
			result += ('0' + iter->second);
			++iter;
		}

		if (!duplicate || str.length() < result.length()) {
			return str;
		}
		
		return result;
	}

};


// Driver code
int main() {
	RLE rleencoding;
	cout << rleencoding.Compression("abc") << endl;
	cout << rleencoding.Compression("bbbaaaadexxxxxx") << endl;


	return 0;
}



#endif // !FORREF


