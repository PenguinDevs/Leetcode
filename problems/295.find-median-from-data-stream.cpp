/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MedianFinder {
priority_queue<int> lower_pq;
priority_queue<int, vector<int>, greater<int>> upper_pq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if (lower_pq.size() <= upper_pq.size()) {
        //     lower_pq.push(num);
        // } else {
        //     upper_pq.push(num);
        // }

        // if (
        //     !lower_pq.empty() && !upper_pq.empty()
        //     && lower_pq.top() > upper_pq.top()
        // ) {
        //     const int lower = lower_pq.top();
        //     lower_pq.pop();

        //     const int upper = upper_pq.top();
        //     upper_pq.pop();

        //     upper_pq.push(lower);
        //     lower_pq.push(upper);
        // }
        if (lower_pq.empty() or lower_pq.top() > num) {
            lower_pq.push(num);
        } else {
            upper_pq.push(num);
        }

        if (lower_pq.size() > upper_pq.size() + 1) {
            upper_pq.push(lower_pq.top());
            lower_pq.pop();
        } else if (upper_pq.size() > lower_pq.size() + 1) {
            lower_pq.push(upper_pq.top());
            upper_pq.pop();
        }
    }
    
    double findMedian() {
        if (lower_pq.size() > upper_pq.size()) {
            return lower_pq.top();
        } else if (lower_pq.size() < upper_pq.size()) {
            return upper_pq.top();
        } else {
            return ((float)lower_pq.top() + (float)upper_pq.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

