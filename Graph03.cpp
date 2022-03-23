/*
	Cycle Detection Using Breadth-First Search
	Time & Space Complexity.
	Time - O(V+E)
	Space - O(V+E) 
*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<queue>
#include<map>
#include<list>

template<class T>
struct Graph {
	map<T, list<T>> adjList;
	Graph() {}

	void addEdge(int u, int v, bool bidir=true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	/*
		if ( visited[neighbour] and parent[node] != neighbour)
		than you will say, you found the cycle in graph
	*/
	bool isCyclicBFS(T src_node) {
		map<T, bool> visited;
		map<T, T> parent;
		queue<T> q;

		// push your source node into queue
		q.push(src_node);
		visited[src_node] = true;
		parent[src_node] = src_node;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			for (T neighbour : adjList[node]) {
				if (visited[neighbour] and parent[node] != neighbour) {
					return true;
				}
				else if (!visited[neighbour]) {
					visited[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}
	
		return false;
	}

};

// Driver code
int main() {
	Graph<int> g;
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(4, 3);
	g.addEdge(2, 3);
	if (g.isCyclicBFS(1))
		cout << "Cyclic Graph";
	else
		cout << "Non cyclic";

}

#endif // !FORREF

