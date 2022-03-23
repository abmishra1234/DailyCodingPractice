/*
	Graph Traversal - Breadth-First Search
	Learn the breadth-first traversal technique to traverse graphs

	BFS :  Graph Traversal
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
	/* 
		Here we are using adjacency list for busilding& representing the graph
		Adjacency list have one advantage over the adjency matrix approach
	*/
	map<T, list<T>> adjList;
	Graph() {
		cout << "Default constructor!!" << endl;

	}

	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void bfs(T src_node) {
		queue<T> q;
		map<T, bool> visited;

		q.push(src_node);
		visited[src_node] = true;

		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();

			for (int neighbour : adjList[node]) {
				if (!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
};

// Driver code 
int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(3, 4);
	g.bfs(0);
	
	return 0;
}




#endif // !FORREF



