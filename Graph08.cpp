/*
	Minimum Spanning Tree - Prims's Algorithm

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<list>
#include<map>
#include<queue>

typedef long long LL;
// x,y,weight for graph structure
typedef map<int, list<pair<int, int>>>  AdjList; 
typedef pair<LL, int> Pair;

struct Graph {
	AdjList adjList;

	void addEdge(int u, int v, int weight) {
		adjList[u].push_back(make_pair(v, weight));
		adjList[v].push_back(make_pair(u, weight));
	}

	LL primsAlgorithm(int startNode, int nodes) {
		LL minCost = 0;
		// Write your code to handle the Prim's algorithm

		// For maintaining the flag for not processing the element twice here
		map<int, bool> marked;

		// Default priority queue is based on max heap
		// Below code for priority queue based on min heap
		std::priority_queue<Pair, vector<Pair>, greater<Pair>> pqueue;
		pqueue.push(make_pair(0, startNode));
		Pair p;

		while (!pqueue.empty()) {
			p = pqueue.top();
			pqueue.pop();

			int x = p.second;

			if (marked[x])
				continue;

			minCost += p.first;
			marked[x] = true;

			for (pair<int, int> tp : adjList[x]) {
				int y = tp.first;
				if (marked[y] == false) {
					pqueue.push(make_pair(tp.second, y));
				}
			}
		}

		return minCost;
	}

};


// Driver code for Testing the Prim's algorithm
int main() {
	Graph g;
	int nodes = 6;
	
	// Edges
	g.addEdge(1, 2, 4);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 2);
	g.addEdge(3, 4, 3);
	g.addEdge(3, 5, 4);
	g.addEdge(3, 6, 2);
	g.addEdge(4, 5, 3);
	g.addEdge(6, 5, 3);

	// let's call the prim's algorithm
	LL ans = g.primsAlgorithm(1, nodes);
	cout << "Minimum Cost = " << ans << endl;

	return 0;
}



#endif // !FORRE


