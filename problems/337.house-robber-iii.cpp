/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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

struct DFSOutput {
    int withNode;
    int withoutNode;
};

class Solution {
public:
    int rob(TreeNode* root) {
        DFSOutput out = dfsRob(root);
        return max(out.withNode, out.withoutNode);
    }
private:
    DFSOutput dfsRob(TreeNode* cur) {
        if (cur == nullptr) return {0, 0};

        DFSOutput leftOut {dfsRob(cur->left)};
        DFSOutput rightOut {dfsRob(cur->right)};

        // vector<int> withNodeOptions;
        // withNodeOptions.reserve(3);
        // withNodeOptions.push_back(cur->val + leftOut.withoutNode + rightOut.withoutNode);
        // if (cur->left != nullptr) withNodeOptions.push_back(cur->val + leftOut.withNode - cur->left->val + rightOut.withoutNode);
        // if (cur->right != nullptr) withNodeOptions.push_back(cur->val + leftOut.withoutNode + rightOut.withoutNode - cur->right->val);

        // vector<int> withoutNodeOptions;
        // withoutNodeOptions.reserve(3);
        // withoutNodeOptions.push_back(leftOut.withNode + rightOut.withoutNode);
        // withoutNodeOptions.push_back(leftOut.withoutNode + rightOut.withNode);
        // withoutNodeOptions.push_back(leftOut.withNode + rightOut.withNode);

        return {
            // *max_element(withNodeOptions.begin(), withNodeOptions.end()),
            // *max_element(withoutNodeOptions.begin(), withoutNodeOptions.end())
            cur->val + max(leftOut.withoutNode, (cur->left != nullptr) ? leftOut.withNode - cur->left->val : 0) + max(rightOut.withoutNode, (cur->right != nullptr) ? rightOut.withNode - cur->right->val : 0),
            max(leftOut.withNode, leftOut.withoutNode) + max(rightOut.withNode, rightOut.withoutNode)
        };
    }
};
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         int capacity {0};
//         bfs(root, [&capacity](TreeNode* cur, int i) {
//             capacity = max(capacity, i + 1);
//         });

//         vector<int> nodes(capacity);
//         vector<int> pqVector;
//         pqVector.reserve(ceil(log2(capacity)) + 1);
//         priority_queue<int> pq(pqVector.begin(), pqVector.end());
//         bfs(root, [&nodes, &pq](TreeNode* cur, int i) {
//             nodes[i] = cur->val;
//             // cout << cur->val << "@" << i << endl;

//             if (cur->left == nullptr && cur->right == nullptr) {
//                 pq.push(i);
//             }
//         });

//         if (capacity <= 3) {
//             int rootValue {nodes[0]};
//             int childrenValue {accumulate(++nodes.begin(), nodes.end(), 0)};
//             return max(rootValue, childrenValue);
//         }

//         // Traverse upwards from leaves
//         vector<int> dp(capacity);
//         auto safeDP = [&dp](int i) {
//             return i < dp.size() ? dp[i] : 0;
//         };

//         while (!pq.empty()) {
//             int nodeIdx {pq.top()};
//             pq.pop();

//             if (dp[nodeIdx]) continue;

//             if (nodeIdx > 0) {
//                 pq.push((nodeIdx - 1) / 2);
//             }

//             // Descendent two levels below
//             const int d2_0 {4 * nodeIdx + 3}; // 2(2i+1)+1=4i+3
//             // Descendent three levels below
//             const int d3_0 {8 * nodeIdx + 7}; // 2(2(2i+1)+1)+1=8i+7
            
//             if (d2_0 > capacity - 1) {
//                 dp[nodeIdx] = nodes[nodeIdx];
//                 continue;
//             }

//             // Try possible combination of viable descendents (2^4 choices)
//             int curMax {nodes[nodeIdx]};
//             for (int i {0}; i < 16; ++i) {
//                 int sum {nodes[nodeIdx]};
//                 for (int j {0}; j < 4; ++j) {
//                     if (i & (1 << j)) {
//                         sum += safeDP(d2_0 + j);
//                     } else {
//                         sum += safeDP(d3_0 + j * 2);
//                         sum += safeDP(d3_0 + j * 2 + 1);
//                     }
//                 }
//                 // cout << "ni:" << nodeIdx << "|nv:" << nodes[nodeIdx] << "|sum:" << sum << endl;
//                 curMax = max(curMax, sum);
//             }
//             dp[nodeIdx] = curMax;
//         }

//         // Try possible combination of possible roots (9 choices)
//         function<int(int, int)> findRootChoiceMax = [&safeDP, &findRootChoiceMax](int initialSum, int i) {
//             if (i < 0) return initialSum;

//             static const int d1_0 {1};
//             static const int d2_0 {3};
//             static const int d3_0 {7};
            
//             int maxSum {initialSum};
//             for (int j {0}; j < 4; ++j) {
//                 int sum {initialSum};

//                 if (j == 0) {
//                     sum += safeDP(d1_0 + i);
//                 } else if (j == 1) {
//                     sum += safeDP(d2_0 + i * 2);
//                     sum += safeDP(d3_0 + 2 + i * 4);
//                     sum += safeDP(d3_0 + 2 + i * 4 + 1);
//                 } else if (j == 2) {
//                     sum += safeDP(d2_0 + i * 2 + 1);
//                     sum += safeDP(d3_0 + i * 4);
//                     sum += safeDP(d3_0 + i * 4 + 1);
//                 } else if (j == 3) {
//                     sum += safeDP(d2_0 + i * 2);
//                     sum += safeDP(d2_0 + i * 2 + 1);
//                 }

//                 // cout << initialSum << " " << sum << " " << j << endl;
//                 maxSum = max(maxSum, findRootChoiceMax(sum, i - 1));
//             }
//             return maxSum;
//         };
//         return max(dp[0], findRootChoiceMax(0, 1));
//     }
// private:
//     void bfs(TreeNode* root, function<void(TreeNode*, int)> callback) {
//         queue<pair<TreeNode*, int>> q;
//         q.push({root, 0});
//         while (!q.empty()) {
//             auto [cur, i] = q.front();
//             q.pop();

//             callback(cur, i);

//             if (cur->left != nullptr) q.push({cur->left, i * 2 + 1});
//             if (cur->right != nullptr) q.push({cur->right, i * 2 + 2});
//         }
//     }
// };
// @lc code=end

