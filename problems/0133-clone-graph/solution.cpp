// 133. Clone Graph [Medium]
// https://leetcode.com/problems/clone-graph/
// Language: C++ | Runtime: 0 ms | Memory: 12.2 MB

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If already cloned, return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a new clone node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Recursively clone all neighbors
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
