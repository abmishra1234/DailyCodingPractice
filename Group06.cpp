/*
	Find the Number of Connected Components in a Graph

	Take your understanding of Depth-First Search to the next level by finding the 
	connected components in a graph.

	Problem Statement:
	Find the connected component in an undirected graph.

	Time :  O(V+E)
	Space : O(V)
*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<map>
#include<list>

template <class T>
struct Graph
{
	map<T, list<T>> adjList;
	Graph() {}

	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void dfsHelper(T node, map<T, bool> &visited) {
		visited[node] = true;
		cout << node << " ";
		for (T neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited);
			}
		}
	}

	// V is the total numver of nodes ( Cities )
	void dfs() {
		map<T, bool> visited;
		int components = 0;

		for (auto i : adjList) {
			T node = i.first;
			if (!visited[node]) {
				dfsHelper(node, visited);
				cout << endl;
				++components;
			}
		}

		cout << "Number of components = " << components << endl;
	}
};

// Driver code 
int main()
{
	Graph<string> g;
	g.addEdge("Amritsar", "Jaipur");
	g.addEdge("Amritsar", "Delhi");
	g.addEdge("Delhi", "Jaipur");
	g.addEdge("Mumbai", "Jaipur");
	g.addEdge("Mumbai", "Bhopal");
	g.addEdge("Delhi", "Bhopal");
	g.addEdge("Mumbai", "Bangalore");
	g.addEdge("Agra", "Delhi");
	g.addEdge("Andaman", "Nicobar");
	g.dfs();
	return 0;
}

#endif // !FORREF







