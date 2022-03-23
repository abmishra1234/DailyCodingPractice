/*
	Topological Sorting Order
	Time : O(V+E)
	Space : O(V)
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<list>
#include<vector>
#include<map>

template<class T>
struct Graph {
	map<T, list<T>> adjList;
	Graph() {}
	
	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	/*
		src - starting your node
		visited - this visited map is to maintain the visited node information
		order - this is to maintain the topological order of node to be processed
	*/
	void dfsHelper(T src, map<T, bool>& visited, list<T>& order) {
		visited[src] = true;
		// call DFS on unvisited neighbours of current src node
		for (T neighbour : adjList[src]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited, order);
			}
		}
		// all the childern of current node is already visited so 
		// now you can add this node into the order list
		order.push_front(src);
	}

	// this method need to be called from main method
	void dfsTopologicalSort() {
		map<T, bool> visited;
		list<T> ordering;

		for (auto i : adjList) {
			// i is the pair of {node, list of nodes}
			T node = i.first;
			if (!visited[node]) {
				dfsHelper(node, visited, ordering);
			}
		}

		for (T ele : ordering) {
			cout << ele << "-->";
		}
		cout << endl;
	}

};



// Driver code
int main() {
	Graph<string> g;
	g.addEdge("English", "Programming Logic", false);
	g.addEdge("Maths", "Programming Logic", false);
	g.addEdge("Programming Logic", "HTML", false);
	g.addEdge("Programming Logic", "Python", false);
	g.addEdge("Programming Logic", "Java", false);
	g.addEdge("Programming Logic", "JS", false);
	g.addEdge("Python", "Web Dev", false);
	g.addEdge("HTML", "CSS", false);
	g.addEdge("CSS", "JS", false);
	g.addEdge("JS", "Web Dev", false);
	g.addEdge("Java", "Web Dev", false);

	g.dfsTopologicalSort();

	return 0;

}







#endif // !FORREF
