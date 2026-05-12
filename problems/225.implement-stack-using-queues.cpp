/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyStack {
public:
    queue<int> q;
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        riseBack();
        const int val = q.front();
        q.pop();

        return val;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
private:
    void riseBack() {
        const int l = q.size();
        for (int i {0}; i < l - 1; ++i) { q.push(q.front()); q.pop(); }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

