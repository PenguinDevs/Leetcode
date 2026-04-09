/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        auto [_, out] = dfs(root, k);

        return out;
    }
private:
    pair<int, int> dfs(TreeNode* currNode, int k, int count = 0) {
        if (currNode == nullptr) return {count, -1};
        // cout << count << " " << (currNode->val) << '\n';
        auto [leftCount, leftValue] = dfs(currNode->left, k, count);
        if (leftCount == k) return {leftCount, leftValue};
        if (leftCount + 1 == k) return {leftCount + 1, currNode->val};
        auto [rightCount, rightValue] = dfs(currNode->right, k, leftCount + 1);
        if (rightCount == k) return {rightCount, rightValue};
        // cout << rightCount << '\n';

        return {rightCount, -1};
    }
};
// @lc code=end

