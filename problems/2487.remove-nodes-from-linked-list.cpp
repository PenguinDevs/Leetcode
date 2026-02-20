/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        ListNode* maxNode = head;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (maxNode->val > curr->val) {
                maxNode->next = curr->next;
                curr = curr->next;
            } else {
                maxNode = curr;
                curr = curr->next;
            }
        }

        return reverseList(head);
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* tail;
        
        ListNode* curr = head;
        ListNode* prev = head;
        while (curr != nullptr) {
            ListNode* newCurr = curr->next;
            curr->next = prev;
            tail = curr;
            prev = curr;
            curr = newCurr;
        }
        head->next = nullptr;

        return tail;
    }
};
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         if (head->next == nullptr) return head;

//         ListNode* successor = removeNodes(head->next);
//         head->next = successor;
//         if (successor->val > head->val) {
//             return head->next;
//         } else {
//             return head;
//         }
//     }
// };
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         ListNode* newHead = head;
//         ListNode* curr = head;
//         stack<ListNode*> prevNodes;
//         while (curr->next != nullptr) {
//             if (curr->next->val > curr->val) {
//                 if (prevNodes.empty()) {
//                     newHead = curr->next;
//                     curr = curr->next;
//                 } else {
//                     prevNodes.top()->next = curr->next;
//                     curr = prevNodes.top();
//                     prevNodes.pop();
//                 }
//             } else {
//                 prevNodes.push(curr);
//                 curr = curr->next;
//             }
//         }

//         return newHead;
//     }
// };
// @lc code=end

