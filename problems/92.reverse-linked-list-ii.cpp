/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count {0};
        ListNode* prevLeftNode;
        ListNode* leftNode = head;
        while (count + 1 < left) {
            prevLeftNode = leftNode;
            leftNode = leftNode->next;
            ++count;
        }
        
        stack<ListNode*> nodesToReverse;
        nodesToReverse.push(leftNode);
        ListNode* rightNode = leftNode;
        while (count + 1 < right) {
            rightNode = rightNode->next;
            nodesToReverse.push(rightNode);
            ++count;
        }
        ListNode* nextRightNode = rightNode->next;
        
        if (leftNode == head) {
            head = rightNode;
        } else {
            prevLeftNode->next = rightNode;
        }
        
        ListNode* prev = nodesToReverse.top();
        nodesToReverse.pop();
        while (!nodesToReverse.empty()) {
            prev->next = nodesToReverse.top();
            prev = nodesToReverse.top();
            nodesToReverse.pop();
        }

        prev->next = nextRightNode;

        return head;
    }
};
// @lc code=end

