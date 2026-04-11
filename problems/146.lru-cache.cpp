/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v, Node* p = nullptr, Node* n = nullptr) : key(k), value(v), prev(p), next(n) {}
};

class LRUCache {
    int capacity;
    int count {0};
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void remove_node(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void push_to_head(Node* node) {
        node->prev = head->prev;
        node->next = head;
        head->prev->next = node;
        head->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0, nullptr, nullptr);
        tail = new Node(0, 0, nullptr, nullptr);
        head->prev = tail;
        tail->next = head;
    }
    
    int get(int key) {
        // cout << "get " << key << '\n';
        if (cache.contains(key)) {
            Node* node = cache[key];
            remove_node(node);
            push_to_head(node);

            return node->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // cout << "put " << key << " " << value << '\n';
        if (cache.contains(key)) {
            Node* node = cache[key];
            node->value = value;
            remove_node(node);
            push_to_head(node);
            return;
        }

        cache[key] = new Node(key, value, nullptr, nullptr);
        push_to_head(cache[key]);
        ++count;

        if (count > capacity) {
            Node* node = tail->next;
            const int key = node->key;
            remove_node(node);
            delete node;
            cache.erase(key);
            --count;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

