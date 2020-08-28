#include<iostream>
#include<vector>
#include<queue>

//Implements binary search trees with inorder, preorder, and breadth first traversal

struct Node {
	int val;
	int parent, left, right;
};

class BST {
private:
	std::vector<Node> tree;
public:
	Node* root = nullptr;

	BST(std::vector<Node> _tree) :tree(_tree){
		if (_tree.size() != 0) {
			root = &tree[0];
		}
		else {
			root = nullptr;
		}
	}

	void InorderTraversal(Node* root) {
		if (root == nullptr) {
			return;
		}
		if (root->left != -1) {
			InorderTraversal(&tree[root->left]);
		}
		std::cout << root->val << " ";
		if (root->right != -1) {
			InorderTraversal(&tree[root->right]);
		}
	}

	void PreOrderTraversal(Node* root) {
		if (root == nullptr) {
			return;
		}
		if (root->left != -1) {
			InorderTraversal(&tree[root->left]);
		}
		if (root->right != -1) {
			InorderTraversal(&tree[root->right]);
		}
		std::cout << root->val << " ";
	}

	void BreadthFirstTraversal(Node* root) {
		if (root == nullptr) {
			return;
		}
		std::queue<Node*> Q;
		Q.push(root);
		while (!Q.empty()) {
			std::cout << Q.front()->val << " ";
			if (Q.front()->left != -1) {
				Q.push(&tree[Q.front()->left]);
			}
			if (Q.front()->right != -1) {
				Q.push(&tree[Q.front()->right]);
			}
			Q.pop();
		}
	}
};