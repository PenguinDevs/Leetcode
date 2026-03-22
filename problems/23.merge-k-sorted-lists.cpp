/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int exhaustedCount {0};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minEntries;
        for (int i {0}; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                minEntries.push({lists[i]->val, i});
            } else {
                ++exhaustedCount;
            }
        }

        if (minEntries.empty()) return nullptr;

        auto insertMinEntry = [&exhaustedCount, &minEntries, &lists](const int listIdx) {
            ListNode* node = lists[listIdx];
            if (node->next != nullptr) {
                ListNode* newNode = node->next;
                lists[listIdx] = newNode;
                minEntries.push({newNode->val, listIdx});
            } else {
                ++exhaustedCount;
            }
        };

        if (minEntries.empty()) return nullptr;

        const auto [_, rootIdx] = minEntries.top();
        ListNode* root = lists[rootIdx];
        minEntries.pop();
        insertMinEntry(rootIdx);
        
        ListNode* current = root;
        while (exhaustedCount < lists.size()) {
            const auto [_, listIdx] = minEntries.top();
            minEntries.pop();
            ListNode* node = lists[listIdx];
            
            insertMinEntry(listIdx);
            
            current->next = node;
            current = node;
        }

        return root;
    }
};
// @lc code=end

