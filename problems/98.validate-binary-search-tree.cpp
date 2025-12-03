/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
struct Entry {
    int lowest;
    int highest;
    TreeNode* node;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<Entry> s;
        // s.push({numeric_limits<int>::min(), numeric_limits<int>::max(), root});
        s.push({0, 0, root});

        while (!s.empty()) {
            auto [lowest, highest, cur] = s.top();
            s.pop();
            
            if (lowest != 0 && highest != 0) {
                if (cur->val >= highest) return false;
                if (cur->val <= lowest) return false;
            }

            if (cur->left != nullptr) {
                if (cur->left->val >= cur->val) return false;
                s.push({lowest, cur->val, cur->left});
            }
            if (cur->right != nullptr) {
                if (cur->right->val <= cur->val) return false;
                s.push({cur->val, highest, cur->right});
            }
        }

        return true;
    }
};
// @lc code=end

