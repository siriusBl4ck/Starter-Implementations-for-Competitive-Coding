#include <iostream>
#include <vector>
#include <queue>

/*
	STRUCTURES FOR USING sskSet
	-> parent array : array of length = #nodes which keeps track of the parent of each node.
	   if a node is root, parent[i] == i
	-> rank array : array of length = #nodes which keeps track of the rank of the subtree of each node
	   rank of singleton set = 0
	-> value array : this is of course, optional, as it stores the value on each node
*/

namespace sskSet {
	void makeSet(std::vector<int>& parent, std::vector<int>& rank, int i) {
		parent[i] = i;
		rank[i] = 0;
	}

	int Find(std::vector<int>& parent, int i) {
		if (i != parent[i]) {
			parent[i] = Find(parent, parent[i]);
		}
		return parent[i];
	}

	void Union(std::vector<int>& parent, std::vector<int>& rank, int i, int j) {
		int i_id = Find(parent, i);
		int j_id = Find(parent, j);

		if (i_id == j_id) {
			return;
		}

		if (rank[i_id] > rank[j_id]) {
			parent[j_id] = i_id;
		}
		else {
			parent[i_id] = j_id;
			if (rank[i_id] == rank[j_id]) {
				rank[j_id]++;
			}
		}
	}
}

struct Edge {
	int v1, v2;
	int wt;
};

struct CompareWt {
	bool operator()(Edge const& e1, Edge const& e2)
	{
		return e1.wt > e2.wt;
	}
};

std::vector<Edge> kruskal(std::vector<int>& parent, std::vector<int>& rank, std::priority_queue<Edge, std::vector<Edge>, CompareWt>& edgeHeap) {
	std::vector<Edge> MST;
	while (!edgeHeap.empty()) {
		int x = sskSet::Find(parent, edgeHeap.top().v1);
		if (sskSet::Find(parent, edgeHeap.top().v1) != sskSet::Find(parent, edgeHeap.top().v2)) {
			MST.push_back(edgeHeap.top());
			sskSet::Union(parent, rank, edgeHeap.top().v1, edgeHeap.top().v2);
		}
		edgeHeap.pop();
	}
	return MST;
}


int main() {
	int v, e;
	std::cin >> v >> e;

	std::priority_queue<Edge, std::vector<Edge>, CompareWt> edgeHeap;

	std::vector<int> parent;
	std::vector<int> rank(v, 0);

	for (int i = 0; i < v; i++) {
		parent.push_back(i);
	}

	while (e--) {
		Edge E;
		std::cin >> E.v1 >> E.v2 >> E.wt;
		
		edgeHeap.push(E);
	}

	std::vector<Edge> MST = kruskal(parent, rank, edgeHeap);

	for (const Edge& e : MST) {
		std::cout << e.v1 << " " << e.v2 << " " << e.wt << "\n";
	}
}
