/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct Node {
    int key;
    int value;
};

class LFUCache {
public:
    int capacity;
    unordered_map<int, Node*> nodes;
    unordered_map<Node*, int> frequencies;
    deque<int> frequencySequence;
    unordered_map<int, deque<Node*>> frequencyToNodes;
    int minFrequency {INT_MAX};

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (nodes.contains(key)) {
            Node* node {nodes[key]};
            const int frequency {frequencies[node]};

            auto &oldQueue = frequencyToNodes[frequency];
            auto it = find(oldQueue.begin(), oldQueue.end(), node);
            if (it != oldQueue.end()) oldQueue.erase(it);

            if (oldQueue.empty()) {
                auto seqIt = find(frequencySequence.begin(), frequencySequence.end(), frequency);
                if (seqIt != frequencySequence.end()) frequencySequence.erase(seqIt);
                if (minFrequency == frequency) {
                    minFrequency = frequencySequence.empty() ? INT_MAX : frequencySequence.front();
                }
            }

            frequencies[node] = frequency + 1;
            auto &newQueue = frequencyToNodes[frequency + 1];
            const bool wasEmpty = newQueue.empty();
            newQueue.push_back(node);
            if (wasEmpty) {
                auto insertPos = lower_bound(frequencySequence.begin(), frequencySequence.end(), frequency + 1);
                frequencySequence.insert(insertPos, frequency + 1);
            }

            minFrequency = frequencySequence.empty() ? INT_MAX : frequencySequence.front();

            return nodes[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if (!nodes.contains(key)) {
            if (nodes.size() >= capacity) {
                deleteLeast();
            }

            Node* node = new Node(key, value);
            nodes[key] = node;
            frequencies[node] = 0;

            auto &q0 = frequencyToNodes[0];
            const bool wasEmpty = q0.empty();
            q0.push_back(node);
            if (wasEmpty) {
                auto insertPos = lower_bound(frequencySequence.begin(), frequencySequence.end(), 0);
                frequencySequence.insert(insertPos, 0);
            }
            minFrequency = frequencySequence.empty() ? INT_MAX : frequencySequence.front();
        } else {
            // treat updating an existing key as an access: increment frequency and refresh recency
            get(key);
            nodes[key]->value = value;
        }
    }
private:
    void deleteLeast() {
        Node* node {frequencyToNodes[minFrequency].front()};
        const int key {node->key};
        frequencyToNodes[minFrequency].pop_front();
        nodes.erase(key);
        frequencies.erase(node);
        delete node;

        if (frequencyToNodes[minFrequency].empty()) {
            frequencySequence.pop_front();
            minFrequency = frequencySequence.empty() ? INT_MAX : frequencySequence.front();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

