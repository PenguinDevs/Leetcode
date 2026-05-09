/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSide;
        dfs(rightSide, root);

        return rightSide;
    }
private:
    void dfs(vector<int>& rightSide, TreeNode* curr, int layer = 0) {
        if (curr == nullptr) return;
        if (layer >= rightSide.size()) {
            rightSide.push_back(curr->val);
        } else {
            rightSide[layer] = curr->val;
        }
        dfs(rightSide, curr->left, layer + 1);
        dfs(rightSide, curr->right, layer + 1);
    }
};
// @lc code=end

