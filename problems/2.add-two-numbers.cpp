/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1Node {l1};
        ListNode* l2Node {l2};

        ListNode* outputRoot {nullptr}; // Root node
        ListNode* outputNode {nullptr};

        int carryOver {0};
        while (l1Node != nullptr || l2Node != nullptr) {
            int digit {carryOver};

            if (l1Node != nullptr) {
                digit += l1Node->val;
                l1Node = l1Node->next;
            }
            if (l2Node != nullptr) {
                digit += l2Node->val;
                l2Node = l2Node->next;
            }

            if (digit >= 10) {
                // Assuming #digit < 3 digits
                int newDigit = digit % 10;
                carryOver = (digit - newDigit) / 10;
                digit = newDigit;
            } else {
                carryOver = 0;
            }
            
            if (outputNode == nullptr) {
                outputNode = new ListNode(digit);
                outputRoot = outputNode;
            } else {
                outputNode->next = new ListNode(digit);
                outputNode = outputNode->next;
            }
        }

        if (carryOver) {
            // Will always have a output node defined here
            outputNode->next = new ListNode(carryOver);
        }
        
        return outputRoot;
    }
};
// @lc code=end

