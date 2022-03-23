/*
	Depth-First Search approach
	Two approch to implement
	1. Using recursion and system stack
	2. Using Iteration & custom stack

	Compare the both approach for Pros and Cons, 
	and get the hands on for both approach 

	Time  Complexity :  O(V+E)
	Space Complexity : O(V)

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<map>
#include<stack>
#include<list>

// Using Template class
template<typename T>
struct Graph {
	map<T, list<T>> adjList;
	Graph() {}

	void addEdge(int u, int v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	// Below is the method for handling the DFS, so focus on this mehtod properly
	void DFS_rec(int src, map<T, bool> &visited) {
		// base condition
		if (visited[src]) {
			return;
		}

		visited[src] = true;
		cout << src << " ";

		for (T neighbour : adjList[src]) {
			if (!visited[neighbour]) {
				DFS_rec(neighbour, visited);
			}
		}
	}
	/*
		Iterative approach for DFS
	*/
	void DFS_iter(int src, map<T, bool>& visited) {
		stack<T> s;
		s.push(src);
		visited[src] = true;

		while (!s.empty()) {
			T node = s.top();
			cout << node << " ";
			s.pop();

			for (T neighbour : adjList[node]) {
				if (!visited[neighbour]) {
					s.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void dfs(int src, bool rec = true) {
		map<T, bool> visited;
		if (rec)
			DFS_rec(src, visited);
		else
			DFS_iter(src, visited);
	}
};

// Driver code
int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.dfs(0, false);

	return 0;
}


#endif // !FORREF

