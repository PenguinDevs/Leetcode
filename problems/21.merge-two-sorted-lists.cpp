/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 != nullptr) return list2;
        if (list1 != nullptr && list2 == nullptr) return list1;

        ListNode* root {nullptr};
        ListNode* currHead {nullptr};
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* nextList = list1->val > list2->val ? list2 : list1;
            if (nextList == list1) {
                list1 = list1->next;
            } else {
                list2 = list2->next;
            }

            if (currHead == nullptr) {
                root = nextList;
                currHead = root;
            } else {
                currHead->next = nextList;
                currHead = nextList;
            }
        }

        if (list1 != nullptr) {
            currHead->next = list1;
        } else if (list2 != nullptr) {
            currHead->next = list2;
        }

        return root;
    }
};
// @lc code=end

