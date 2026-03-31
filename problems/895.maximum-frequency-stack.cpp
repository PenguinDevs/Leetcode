/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class FreqStack {
    unordered_map<int, int> freqMap;
    unordered_map<int, stack<int>> stackMap;
    int max_freq {0};

public:
    FreqStack() {
        
    }
    
    void push(int val) {
        // cout << "push " << val << '\n';
        ++freqMap[val];
        stackMap[freqMap[val]].push(val);
        max_freq = max(max_freq, freqMap[val]);
    }
    
    int pop() {
        // cout << "pop at " << max_freq << '\n';

        // cout << max_freq << " " << stackMap[max_freq].size() << '\n';
        const int found = stackMap[max_freq].top();
        stackMap[max_freq].pop();
        if (stackMap[max_freq].empty()) {
            stackMap.erase(max_freq);
            --max_freq;
        }
        --freqMap[found];

        return found;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

