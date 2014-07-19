/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node,
		map<int, UndirectedGraphNode *> &nodeMap) {
		if (node) {
			int label = node->label;
			if (nodeMap.find(label) == nodeMap.end()) {
				UndirectedGraphNode *newNode = new UndirectedGraphNode(label);
				nodeMap[label] = newNode;
				int numOfNeigh = node->neighbors.size();
				for (int i=0; i<numOfNeigh; i++) {
					newNode->neighbors.push_back(cloneGraphHelper(node->neighbors[i], nodeMap));
				}
			}

			return nodeMap[label];
		}

		return NULL;
	}

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	map<int, UndirectedGraphNode *> nodeMap;
    	return cloneGraphHelper(node, nodeMap);
    }
};