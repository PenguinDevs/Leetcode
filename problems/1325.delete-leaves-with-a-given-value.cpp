/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return !removeLeafNodesAux(root, target) ? root : nullptr;
    }
private:
    bool removeLeafNodesAux(TreeNode* cur, int target) {
        if (cur->left != nullptr) {
            if (removeLeafNodesAux(cur->left, target)) cur->left = nullptr;
        }
        if (cur->right != nullptr) {
            if (removeLeafNodesAux(cur->right, target)) cur->right = nullptr;
        }

        return cur->left == nullptr && cur->right == nullptr && cur->val == target;
    }
};
// @lc code=end

