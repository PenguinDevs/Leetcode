/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <bits/stdc++.h>
using namespace std;

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

// @lc code=start
/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        vector<Node*> nodes;
        unordered_map<Node*, int> nodeToIdx;

        Node* newGraphNode = new Node(node->val);
        nodes.push_back(newGraphNode);
        nodeToIdx[newGraphNode] = 0;

        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (Node* neighbour : curr->neighbors) {
                if (!nodeToIdx.contains(neighbour)) {
                    Node* newNode = new Node(neighbour->val);
                    nodes.push_back(newNode);
                    nodeToIdx[neighbour] = nodes.size() - 1;
                    q.push(neighbour);
                };

                nodes[nodeToIdx[curr]]->neighbors.push_back(nodes[nodeToIdx[neighbour]]);
            }
        }

        return newGraphNode;
    }
};
// @lc code=end
