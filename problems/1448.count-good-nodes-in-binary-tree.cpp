/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        return dfsCountMins(root);
    }
private:
    int dfsCountMins(TreeNode* currNode, int currMax = INT_MIN) {
        if (currNode == nullptr) return 0;

        // cout << currNode->val << " " << currMax << " " << (currNode->val >= currMax) << '\n';

        return dfsCountMins(currNode->left, max(currMax, currNode->val))
        + dfsCountMins(currNode->right, max(currMax, currNode->val))
        + (currNode->val >= currMax ? 1 : 0);
    }
};
// @lc code=end

