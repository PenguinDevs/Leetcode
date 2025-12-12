/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        auto [_, output] = getDiameter(root, 0, 0);
        return output;
    }
private:
    pair<int, int> getDiameter(TreeNode* current, int height, int longestDist) {
        if (current == nullptr) return {height - 1, longestDist};
        
        auto [leftHeight, leftLongest] = getDiameter(current->left, height + 1, longestDist);
        auto [rightHeight, rightLongest] = getDiameter(current->right, height + 1, longestDist);
        
        // cout << current->val << " " << leftHeight << " " << rightHeight << endl;

        return {max(leftHeight, rightHeight), max(leftHeight + rightHeight - height * 2, max(longestDist, max(leftLongest, rightLongest)))};
    }
};
// @lc code=end

