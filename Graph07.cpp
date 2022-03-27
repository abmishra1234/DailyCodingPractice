/*
	Coding Exercise #1
	How to detect the cycle into the undirected graph.
	Algoritm
	1. Prepare the Graph first which is the input for your logic to verify that 
	    does this undirected graph is cyclic or not?
		
		// bool isCyclic(adjList)
	
	2. Than think to use this logic into your overall implementation of MST ( Minimum Spanning Tree )

	3. 

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<algorithm>

// you are creating below some of the type in cpp
// kind of alias to avoid long name for multiple
typedef long long LL;
typedef pair<int, pair<int, int>> Edge;
typedef vector<Edge> EdgeList; // <weight of edge <start vectex, end vertex>>

struct MST {
	EdgeList edgelist;
	int V; /* V is the total number of vertex*/
	MST() {}

	void addEdge(int weight, int u, int v /* u and v are vertices */)
	{
		edgelist.push_back(make_pair(weight, make_pair(u, v)));
	}

	// Let's write method who sort their edges according to their weights
	void sortEdges() {
		sort(edgelist.begin(), edgelist.end());
	}

	/*
		Write oen utility method for finding the absolute root for the given vertex
	*/
	int absoluteRoot(int node, vector<int>& parents, vector<int>& ranks) {
		while (parents[node] != -1) {
			node = parents[node];
		}
		return node;
	}

	/*
		How you will determine using Find union that be adding
		the upcoming Edge will form or not the cycle?

		Union & Find method will work here
		Edge have two vertex right?
		You need to check their absolute root and the vertex rank

		nv - number of vertex into the given graph

	*/
	LL MST_Kruskal(int nv) {
		V = nv + 1;
		LL mincost = 0;
		vector<int> parents(V, -1);
		vector<int> ranks(V, 0);
		int edgeCnt = 0;

		for (int i = 0; i < edgelist.size(); ++i) {
			Edge e = edgelist[i];
			int u = e.second.first;
			int v = e.second.second;

			int absr_u = absoluteRoot(u, parents, ranks);
			int absr_v = absoluteRoot(v, parents, ranks);

			if (absr_u == absr_v) {
				continue;
			}
			else
			{
				// so you reached the point where you can add new edge into MST
				++edgeCnt;
				mincost += e.first;
				/*
					You have to update the parent table and rank table
					because these two could be again used for handling the
					union of two subset
				*/
				if (ranks[absr_u] >= ranks[absr_v]) {
					parents[v] = u;
					ranks[u] += 1;
				}
				else
				{
					parents[u] = v;
					ranks[v] += 1;
				}
			}

			if (edgeCnt == V - 1)
				break;
		}
		return mincost;
	}
};

/*
	One thing very important in case you want to convert
	forest(graph) into minimum spanning tree than you have to follow the below algorithm
	1. First fundamental step is minimum cost and that would be possible if you
	will choose the all required edges with minimum weight/cost
	- Sort the edges according to the weight / cost
	2. With V number of vertex , maximum edges could be include V-1 with assumption that
	any edge is not forming the cycle

*/

// Driver code
int main() {
	LL minimumCost = 0;
	MST mst;
	mst.addEdge(4, 1, 2);
	mst.addEdge(4, 1, 3);
	mst.addEdge(2, 2, 3);
	mst.addEdge(3, 3, 4);
	mst.addEdge(4, 3, 5);
	mst.addEdge(2, 3, 6);
	mst.addEdge(3, 4, 5);
	mst.addEdge(3, 6, 5);

	// Now sort the Edges
	mst.sortEdges();

	LL ans = mst.MST_Kruskal(6);
	cout << "Min Cost = " << ans << endl;

	return 0;
}


#endif // !FORREF



