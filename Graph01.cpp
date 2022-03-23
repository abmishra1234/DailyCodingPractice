/*
	Introduction to Graphs
	Using the Adjacency List

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<list>

typedef list<int> List;
typedef List* ListP;

struct Graph {
	ListP* adjlist;
	int V;
	Graph(int v/* number of vertex*/)
	{
		V = v;
		adjlist = new ListP[v + 1];
		for (int i = 0; i < v; ++i) {
			adjlist[i] = nullptr;
		}
	}

	// Method for adding an Edge
	void addEdge(int sv, int dv, bool bidir = true) {
		if (adjlist[sv] == nullptr) {
			adjlist[sv] = new List();
		}
		adjlist[sv]->push_back(dv);

		if (bidir) {
			if (adjlist[dv] == nullptr) {
				adjlist[dv] = new List();
			}
			adjlist[dv]->push_back(sv);
		}
	}

	void printAdjList()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << "->";
			List::iterator it = adjlist[i]->begin();
			while (it != adjlist[i]->end()) {
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}
	}
};


// Driver code
int main() {
	Graph gr(5);
	gr.addEdge(0, 1);
	gr.addEdge(0, 4);
	gr.addEdge(4, 3);
	gr.addEdge(1, 4);
	gr.addEdge(1, 2);
	gr.addEdge(2, 3);
	gr.addEdge(1, 3);

	gr.printAdjList();
	return 0;
}





#endif // !FORREF



