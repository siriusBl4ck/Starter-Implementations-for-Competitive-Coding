#include <iostream>
#include <vector>
#include <algorithm>

//Implements undirected graph and DFS to find longest path in an n-ary tree

struct Node {
	int depthOfSubtree = 0;
	std::vector<int> children;
	bool visited = false;
};

class nAryTree {
private:
	std::vector<Node> tree;
	int maxDepth = 0, secondMaxDepth = 0;
public:
	Node* root = nullptr;

	nAryTree(std::vector<Node> _tree) :tree(_tree) {
		if (_tree.size() != 0) {
			root = &tree[0];
		}
		else {
			root = nullptr;
		}
	}
	
	void DFS(Node* root) {
		if (root == nullptr) {
			return;
		}
		else {
			root->visited = true;
		}

		for (int child : root->children) {
			if (!tree[child].visited) {
				DFS(&tree[child]);
				if (root->depthOfSubtree < tree[child].depthOfSubtree + 1) {
					root->depthOfSubtree = tree[child].depthOfSubtree + 1;
				}
			}
		}

		if (root->children.size() == 0) {
			root->depthOfSubtree = 0;
		}
	}

	int MaxDist() {
		DFS(root);
		std::vector<int> depths;
		for (int child : root->children) {
			depths.push_back(tree[child].depthOfSubtree);
		}

		std::sort(depths.begin(), depths.end(), std::greater<int>());

		if (depths.size() >= 2) {
			return depths[0] + depths[1] + 2;
		}
		else if (depths.size() == 1) {
			return depths[0] + 1;
		}
		else {
			return 0;
		}
	}
};