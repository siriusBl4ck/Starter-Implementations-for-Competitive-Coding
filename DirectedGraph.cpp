#include <vector>
#include <queue>

//This file implements a structure which keeps track of which nodes are accessible
//from which node in a directed graph

struct Node {
	std::vector<int> neighbors;
	std::vector<int> reachables;
	int index;
};

struct CompareReach {
	bool operator()(Node const& p1, Node const& p2)
	{
		return p1.reachables.size() < p2.reachables.size();
	}
};

class directedGraph {
private:
	std::vector<Node> graph;
	
public:
	directedGraph(std::vector<Node> g)
		: graph(g) {

	}

	void Probe(int index) {
		if (graph[index].reachables.size() == 0) {
			graph[index].reachables.push_back(index);
		}
		for (int childIndex : graph[index].neighbors) {
			Probe(childIndex);
			for (int child : graph[childIndex].reachables) {
				if (std::find(graph[index].reachables.begin(), graph[index].reachables.end(), child) == graph[index].reachables.end()) {
					graph[index].reachables.push_back(child);
				}
			}
		}
	}

	std::vector<int> returnReachables() {
		std::priority_queue<Node, std::vector<Node>, CompareReach> order;
		
		for (int i = 0; i < graph.size(); i++) {
			Probe(i);
			order.push(graph[i]);
		}

		std::vector<int> total;
		std::vector<int> verts;

		while (!order.empty() && total.size() != graph.size()) {
			total = IntersectionCovers(total, order.top());
			verts.push_back(order.top().index);
			order.pop();
		}

		return verts;
	}

	std::vector<int> IntersectionCovers(std::vector<int>& p1, Node p2) {
		std::vector<int> totalReach(p1);

		for (int child : p2.reachables) {
			if (std::find(p1.begin(), p1.end(), child) == p1.end()) {
				totalReach.push_back(child);
			}
		}

		return totalReach;
	}
};