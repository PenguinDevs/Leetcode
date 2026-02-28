/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        deque<ListNode*> arrangment;
        
        {
            ListNode* curr = head;
            while (curr != nullptr) {
                arrangment.push_back(curr);
                curr = curr->next;
            }
        }

        
        {
            ListNode* curr = head;
            bool useEnd {false};
            while (!arrangment.empty()) {
                ListNode* newNode;
                if (useEnd) {
                    newNode = arrangment.back();
                    arrangment.pop_back();
                } else {
                    newNode = arrangment.front();
                    arrangment.pop_front();
                }

                curr->next = newNode;
                curr = newNode;

                useEnd = !useEnd;
            }

            curr->next = nullptr;
        }
    }
};
// @lc code=end

