/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        
        int count {0};
        ListNode* curr = head;
        while (curr->next) {
            nodes.push_back(curr);
            curr = curr->next;
            ++count;
        }
        nodes.push_back(curr);

        // if (nodes.size() == 0)
        // cout << nodes.size() << '\n';

        ListNode* removedNode = nodes[nodes.size() - n];
        if (removedNode == head) {
            head = removedNode->next;
        } else {
            nodes[nodes.size() - n - 1]->next = removedNode->next;
        }
        delete removedNode;

        return head;
    }
};
// @lc code=end

