/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p, q); // p < q
        auto lca = dfs(root, p, q);
        
        return lca;
    }
private:
    TreeNode* dfs(TreeNode* current, TreeNode* p, TreeNode* q) {
        if (current == nullptr) return nullptr;
        
        // cout << (q->val) << " " << (p->val) << " " << (current->val);
        if (q->val < current->val) {
            // Since p < q < current
            return dfs(current->left, p, q);
        } else if (p->val > current->val) {
            // Since q > p > current
            return dfs(current->right, p, q);
        }


        return current;
    }
};
// @lc code=end

