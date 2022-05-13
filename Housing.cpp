/*
	Housing Problem and Solution
	Target Timeline : O(n)
	Space Complecity :  O(1)

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

typedef std::pair<int, int> Pair;
typedef vector<Pair> PairVect;
typedef vector<int> Plots;

struct Housing {
	/*
		This implementation talk about the sliding window concept
		Time:
		Space:
	
		Example 01
		input : [2, 5, 3, 5, 6, 1, 1, 8]
		k = 8
		output : [(1,2), (2,3), (3,5),(7,7)]

		Example 02
		input : []
		K = 2
		output : []

		Example 03
		// No possible solution
		input : [1,1,1,1,1,1,1,1]
		K=9
		output : []
	*/
	PairVect solve(Plots plots, int k /* k is the required area for house*/) {
		PairVect output;
		int psize = plots.size();
		int s = 0, e = 0;
		int lsum = 0;

		while (true) {
			// infinite loop
			if (e == psize)
				break;
			lsum += plots[e];
			if (lsum < k)
			{
				if (e == psize - 1)
					break;
				++e;
			}
			else if (lsum > k) {
				while (lsum > k) {
					lsum -= plots[s];
					++s;
				}
				if (lsum == k) {
					Pair pair;
					pair.first = s;
					pair.second = e;
					output.push_back(pair);
				}
				++e;
			}
			else
			{
				// this  is the case when you found the sum exactly the k
				Pair pair;
				pair.first = s;
				pair.second = e;
				output.push_back(pair);

				if (e == psize - 1) {
					break;
				}
				++e;
			}
		}

		return output;
	}
};

// Driver code 
int main() {
	Housing hs;
	int k = 8;
	vector<int> arr{ 1,3,2,1,4,1,3,2,1,1,2 };
	PairVect res = hs.solve( arr, k);
	
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << " , " << res[i].second << endl;
	}

	return 0;
}

#endif // !FORREF


