#include <iostream>
using namespace std;

class Graph {
    vector<Node*> roots;

public:
    vector<Node*> getRoots() {
        return this->roots;
    }
};

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloneMap) {
        if (node == nullptr) {
            return nullptr;
        }
        if (cloneMap.count(node)) {
            return cloneMap[node];
        }
        Node* cloneNode = new Node(node->val);
        cloneMap[node] = cloneNode;

        for (auto neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neighbor, cloneMap));
        }
        return cloneNode;
    }

public:
    Graph cloneGraph(Graph& input) {
        Graph output;
        for (auto node : input.getRoots()) {
            if (node == nullptr) {
                continue;
            }
            unordered_map<Node*, Node*> oldToNew;
            output.getRoots().push_back(dfs(node, oldToNew));
        }
        return output;
    }
};
