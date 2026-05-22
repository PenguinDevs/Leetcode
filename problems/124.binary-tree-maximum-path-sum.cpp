/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        const auto [leftPath, leftGlobalMax] = traverse(root->left);
        const auto [rightPath, rightGlobalMax] = traverse(root->right);
        return max(leftGlobalMax, max(rightGlobalMax, root->val + max(leftPath, 0) + max(rightPath, 0)));
    }
private:
    pair<int, int> traverse(TreeNode* curr) {
        if (curr == nullptr) return {-1001, -1001};
        
        const auto [leftPath, leftGlobalMax] = traverse(curr->left);
        const auto [rightPath, rightGlobalMax] = traverse(curr->right);
        const int currentGlobalMax = curr->val + max(leftPath, 0) + max(rightPath, 0);

        return {
            curr->val + max(max(leftPath, rightPath), 0),
            max(leftGlobalMax, max(rightGlobalMax, currentGlobalMax))
        };
    }
};
// @lc code=end

