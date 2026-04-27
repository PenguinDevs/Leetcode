/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int count {0};
        ListNode* curr = head;
        while (curr->next != nullptr) {
            ListNode* newNode = new ListNode(gcd(curr->val, curr->next->val));
            newNode->next = curr->next;
            curr->next = newNode;

            curr = curr->next->next;
        }

        return head;
    }
// private:
//     int GCD(const int x, const int y) {
        
//     }
};
// @lc code=end

