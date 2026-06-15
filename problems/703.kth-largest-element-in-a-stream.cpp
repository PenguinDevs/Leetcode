/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (const int x : nums) add(x);
    }
    
    int add(const int val) {
        if (q.size() < k || q.top() < val) {
            q.push(val);
            if (q.size() > k) q.pop();
        }

        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

