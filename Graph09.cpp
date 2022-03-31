/*
	Dijkstra's Algorithm
	Find the shortest path to traverse a graph using Dijkstra's Algorithm.

	The shortest path problem is about finding a path between 2 vertices 
	in a graph such that the total sum of the weights of the edges is minimum.

	This problem could be solved easily using BFS if all edge weights were (1), 
	but here weights can take any value.

	Let’s discuss Dijkstra’s Algorithm that works to find the shortest path between two vertices.

	Dijkstra’s Algorithm
	Dijkstra’s Algorithm solves the single-source shortest-path problem on a weighted, 
	directed graph G = (V, E) for the case where all edge weights are non-negative.

	@Note:  If their is any edge with negative weight than you should either transform weight of
	all edges are may be choose some other algorithm

	So, for now let's define the set of steps used in Dijkstra algorithm
	1. Set all the vertices distance to infinity except for the source vertex or starting vertex
	
	2. Push the source vertex in a min-priority queue or min heap based priority queue as a pair
	of {distance, vertex}
	
	3. Pop the vertex with minimum distance from the priority queue 
	   ( at first the popped vertex = source )

	4. Update the distance of the connected vertices to the popped vertex, in case of
	current vertex distance + edge weight < next vertex distance, and then push the vertex with 
	the new distance to the priority queue

	5. If the popped vertex is visited before, just continue without using it.

	6. Apply the same algorithm again until the priority queue is empty.

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include <queue>
#include<set>

template<class T>
struct Graph {
	unordered_map < T, list<pair<T, int>>> adjList;

	void addEdge(T u, T v, int weight, bool bidir = true) {
		adjList[u].push_back(make_pair(v, weight));
		if(bidir)
			adjList[v].push_back(make_pair(u, weight));
	}

	void printEdges() {
		for (auto p : adjList) {
			cout << p.first << "->";
			for (auto l : p.second) {
				cout << "(" << l.first << ", " << l.second << ")";
			}
			cout << endl;
		}
	}
	
	// Dijkstra Algorithm Implementation
	void dijkstra(T src) {
		unordered_map<T, int> dist;

		// Step 01 : Assign dist for ll vertex to infinity except the src vertex
		for (auto j : adjList) {
			if (j.first == src) {
				dist[j.first] = 0;
			}
			else
				dist[j.first] = INT_MAX;
		}

		// Step 02 : push the src into the priority queue or any DS which will be 
		// used to maintain the element in order
		set<pair<int, T>> pqueue; // this is to maintain the element in order
		pqueue.insert(make_pair(0, src));

		// Step 03 - Update the distance for the connected vertex
		while (!pqueue.empty()) {
			auto p = *(pqueue.begin());
			T node = p.second;
			int nodeDist = p.first;
			pqueue.erase(pqueue.begin());

			for (auto neighbour : adjList[node]) {
				// as a neighbour you have pair of dest vertex and weight of edge




			}


		
		}


	}

};




// Driver code
int main() {
	Graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);

	// Just print the all edges of the graph
	g.printEdges();



	return 0;
}



#endif // !FORREF


