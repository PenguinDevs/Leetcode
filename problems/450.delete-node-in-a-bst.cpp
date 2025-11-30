/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
struct NodeWithParent {
    TreeNode* node;
    TreeNode* parent;
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        auto [node, parent] = findNode(root, key);

        if (node == nullptr) {
            // Doesn't exist in BST
            return root;
        }

        TreeNode* nodeToReplaceWith;
        if (node->right != nullptr) {
            // Prioritise the left-most node of the right tree
            nodeToReplaceWith = node->right;
            TreeNode* previousNode;
            while (nodeToReplaceWith->left != nullptr) {
                previousNode = nodeToReplaceWith;
                nodeToReplaceWith = nodeToReplaceWith->left;
            }
            
            nodeToReplaceWith->left = node->left;
            if (node->right != nodeToReplaceWith) {
                if (previousNode != nullptr) previousNode->left = nodeToReplaceWith->right;
                nodeToReplaceWith->right = node->right;
            }
        } else {
            nodeToReplaceWith = node->left;
        }
            
        if (parent != nullptr) {
            if (parent->left == node) {
                parent->left = nodeToReplaceWith;
            } else {
                parent->right = nodeToReplaceWith;
            }
        } else {
            // Otherwise, it is the root node that is deleted
            root = nodeToReplaceWith;
        }

        return root;
    }
private:
    NodeWithParent findNode(TreeNode* current, int target, TreeNode* previous = nullptr) {
        if (current->val == target) {
            return {current, previous};
        } else if (current->left != nullptr && target < current->val) {
            return findNode(current->left, target, current);
        } else if (current->right != nullptr && target > current->val) {
            return findNode(current->right, target, current);
        } else {
            return {nullptr, previous};
        }
    }
};
// @lc code=end

