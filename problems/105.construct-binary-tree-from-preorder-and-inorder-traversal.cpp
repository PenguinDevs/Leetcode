/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderValToIdx;

        for (int i {0}; i < inorder.size(); ++i) {
            inorderValToIdx[inorder[i]] = i;
        }

        return buildSubTree(preorder, inorder, inorderValToIdx, 0, 0, preorder.size());
    }
private:
    TreeNode* buildSubTree(
        vector<int>& preorder,
        vector<int>& inorder,
        unordered_map<int, int>& inorderValToIdx,
        int preorderIdx,
        int l,
        int r
    ) {
        if (l >= r || preorderIdx >= preorder.size()) return nullptr;
        const int currValue = preorder[preorderIdx];
        const int rootInorderIdx = inorderValToIdx[currValue];
        const int leftSize = rootInorderIdx - l;
        TreeNode* currNode = new TreeNode(currValue);

        
        currNode->left = buildSubTree(
            preorder,
            inorder,
            inorderValToIdx,
            preorderIdx + 1,
            l,
            rootInorderIdx
        );
        currNode->right = buildSubTree(
            preorder,
            inorder,
            inorderValToIdx,
            preorderIdx + 1 + leftSize,
            rootInorderIdx + 1,
            r
        );

        return currNode;
    }
};
// @lc code=end

