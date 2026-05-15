/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyCircularQueue {
public:
    vector<int> arr;
    int l {0};
    int r {-1};

    MyCircularQueue(int k) {
        arr.resize(k);
    }
    
    bool enQueue(int value) {
        const int k = arr.size();
        if (isFull()) return false;
        
        ++r;
        arr[r % k] = value;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        const int k = arr.size();
        ++l;
        
        return true;
    }
    
    int Front() {
        const int k = arr.size();
        return !isEmpty() ? arr[l % k] : -1;
    }
    
    int Rear() {
        const int k = arr.size();
        return !isEmpty() ? arr[r % k] : -1;
    }
    
    bool isEmpty() {
        return l >= r + 1;
    }
    
    bool isFull() {
        const int k = arr.size();
        return l == r - k + 1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

