#include <iostream>
#include <vector>

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