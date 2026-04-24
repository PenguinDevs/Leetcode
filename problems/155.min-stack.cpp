/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MinStack {
    int currMin = INT_MAX;
    stack<pair<int, long long>> values;
public:
    void push(int val) {
        values.push({val, (long long)val - currMin});
        if (val < currMin) currMin = val;
    }
    
    void pop() {
        const auto [val, diff] = values.top();
        values.pop();

        if (val == currMin) {
            currMin += -diff;
        }
    }
    
    int top() {
        return values.top().first;
    }
    
    int getMin() {
        return currMin;
    }
};
// struct Node {
//     int value;
//     Node* next;
//     Node* prev;
// };

// class MinStack {
//     Node* head;
//     Node* tail;
//     stack<Node*> valueStack;
// public:
//     MinStack() {
//         head = new Node(0, nullptr, tail);
//         tail = new Node(0, head, nullptr);
//     }
    
//     void push(int val) {
//         cout << "push " << val << '\n';
//         Node* entry = new Node(val, head, head->prev);
//         head->prev->next = entry;
//         entry->prev = head->prev;
//         head->prev = entry;
//         entry->next = head;
//         valueStack.push(entry);
//     }
    
//     void pop() {
//         cout << "pop\n";
//         Node* entry = valueStack.top();
//         valueStack.pop();
//         entry->prev->next = entry->next;
//         entry->next->prev = entry->prev;
//         delete entry;
//     }
    
//     int top() {
//         cout << "top\n";
//         Node* entry = valueStack.top();
//         return entry->value;
//     }
    
//     int getMin() {
//         cout << "get min\n";
//         return tail->next->value;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

