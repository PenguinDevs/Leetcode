/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto [balanced, _] = dfs(root);

        return balanced;
    }
private:
    pair<bool, int> dfs(TreeNode* currNode, const int depth = 0) {
        if (currNode == nullptr) return {true, depth};

        auto [leftBalanced, leftDepth] = dfs(currNode->left, depth + 1);
        auto [rightBalanced, rightDepth] = dfs(currNode->right, depth + 1);

        if (!leftBalanced || !rightBalanced) return {false, depth};
        // cout << leftDepth << " " << rightDepth << '\n';
        if (abs(leftDepth - rightDepth) > 1) return {false, depth};

        return {true, max(leftDepth, rightDepth)};
    }
};
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (root == nullptr) return true;

//         vector<int> layerCount;
        
//         queue<pair<int, TreeNode*>> q;
//         q.push({0, root});
//         while (!q.empty()) {
//             auto [layer, node] = q.front();
//             q.pop();

//             if (layer >= layerCount.size()) layerCount.push_back(0);
//             ++layerCount[layer];

//             if (node->left != nullptr) q.push({layer + 1, node->left});
//             if (node->right != nullptr) q.push({layer + 1, node->right});
//         }

//         for (int i {0}; i < layerCount.size() - 1; ++i) {
//             if (layerCount[i] != pow(2, i)) return false;
//         }

//         return true;
//     }
// };
// @lc code=end

