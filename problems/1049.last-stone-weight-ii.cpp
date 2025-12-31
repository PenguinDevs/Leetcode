/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 *
 * NOTE: For problems with complex behaviours, seek for a simple solution or
 * problem reduction.
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        const int sum = accumulate(stones.begin(), stones.end(), 0);
    
        vector<int> dp(sum / 2 + 1);
        for (const int s : stones) {
            for (int i {sum / 2}; i >= s; --i) {
                dp[i] = max(dp[i], dp[i - s] + s);
            }
        }

        return sum - 2 * dp[sum/2];
    }
};
// class Solution {
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         const int n = stones.size();
//         const int sum = accumulate(stones.begin(), stones.end(), 0);

//         vector<vector<int>> dp(n, vector<int>(sum / 2 + 1));
//         for (int i {0}; i < n; ++i) {
//             for (int j {1}; j <= sum / 2; ++j) {
//                 if (j >= stones[i]) {
//                     if (i > 0) {
//                         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
//                     } else {
//                         dp[i][j] = stones[i];
//                     }
//                 } else {
//                     if (i > 0) dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }

//         return sum - 2 * dp[n - 1][sum / 2];
//     }
// };

// struct Node {
//     int val;
//     Node* next;
//     Node* prev;
// };

// class Solution {
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         sort(stones.begin(), stones.end());

//         Node* head = new Node(stones[0]);
//         Node* tail = head;
//         for (int i {1}; i < stones.size(); ++i) {
//             Node* newNode = new Node(stones[i]);
//             newNode->prev = tail;
//             tail->next = newNode;
//             tail = newNode;
//         }

//         while (head != tail) {
//             if (head->next != tail) {
//                 // More than two nodes
//                 // cout << "head1: " << head->val << "head2: " << head->next->val << " tail: " << tail->val << endl;
//                 const int newVal = tail->val - head->next->val;
//                 // cout << "new value: " << newVal << endl;
                
//                 Node* toDelete1 = head->next;
//                 head->next = toDelete1->next;
//                 toDelete1->next->prev = head;
//                 // delete toDelete1;

//                 Node* toDelete2 = tail;
//                 tail = tail->prev;
//                 tail->next = nullptr;
//                 // delete toDelete2;

//                 auto [newHead, newTail] = insertInSortedLinkedList(newVal, head, tail);
//                 // cout << "new head" << newHead->val << "new tail" << newTail->val << endl;
//                 head = newHead;
//                 tail = newTail;
//             } else {
//                 // cout << (tail->val) << " " << (head->val) << endl;
//                 return tail->val - head->val;;
//             }
//         }

//         return stones[0]; // Occurs when there was only stone
//     }
// private:
//     pair<Node*, Node*> insertInSortedLinkedList(const int newVal, Node* head, Node* tail) {
//         Node* newNode = new Node(newVal);

//         if (newVal <= head->val) {
//             // Append to head instead because it is the smallest value
//             newNode->next = head;
//             head->prev = newNode;

//             return {newNode, tail};
//         }

//         Node* cur = head;
//         while (cur->next != nullptr) {
//             if (newVal > cur->val && newVal < cur->next->val) {
//                 newNode->next = cur->next;
//                 cur->next->prev = newNode;

//                 cur->next = newNode;
//                 newNode->prev = cur;

//                 return {head, tail};
//             }
//             cur = cur->next;
//         }

//         // Append to the end instead because it is the largest value
//         cur->next = newNode;
//         newNode->prev = cur;

//         return {head, newNode};
//     }
// };
// @lc code=end

