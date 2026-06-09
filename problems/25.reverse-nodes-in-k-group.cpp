/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead {nullptr};
        ListNode* prevGroupTail {nullptr};
        while (head) {
            ListNode* lastNode;
            {
                bool hasLengthFlag {true};
                ListNode* curr = head;
                for (int i {0}; i < k; ++i) {
                    if (curr == nullptr) {
                        hasLengthFlag = false;
                        break;
                    }
                    curr = curr->next;
                }

                lastNode = curr;
                if (!hasLengthFlag) break;
            }

            {
                ListNode* curr = nullptr;
                ListNode* prev = lastNode;
                ListNode* groupTail = head;
                for (int i {0}; i < k; ++i) {
                    curr = head->next;
                    head->next = prev;
                    prev = head;
                    head = curr;
                }

                if (newHead == nullptr) newHead = prev;
                if (prevGroupTail != nullptr) prevGroupTail->next = prev;
                prevGroupTail = groupTail;
            }
        }

        return newHead ? newHead : head;
    }
};
// @lc code=end

