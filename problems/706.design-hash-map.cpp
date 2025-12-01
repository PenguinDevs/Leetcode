/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyHashMap {
public:
    static constexpr double LOAD_FACTOR_THRESH {0.75};
    static constexpr int INITIAL_CAPACITY {16};

    vector<pair<int, int>> map;
    int length {0};

    MyHashMap() {
        map.resize(INITIAL_CAPACITY, {-1, 0});
    }
    
    void put(int key, int value) {
        int i = probe(key, hash(key));
        // cout << i << endl;
        if (i == -1) {
            resize();
            return put(key, value);
        } else {
            // cout << "assigning " << value << " at " << key << " #" << i << endl;
            if (map[i].first == -1) {
                map[i] = {key, value};
                ++length;
                
                if (length > map.size() * LOAD_FACTOR_THRESH) {
                    resize();
                }
            } else {
                map[i] = {key, value};
            }
        }
    }
    
    int get(int key) {
        int i = probe(key, hash(key));
        // cout << i << endl;
        if (i == -1) {
            resize();
            return get(key);
        } else if (map[i].first == key) {
            // cout << "got " << map[i].second << " at " << map[i].first << " #" << i << endl;
            return map[i].second;
        } else {
            return -1;
        }
    }
    
    void remove(int key) {
        int i = probe(key, hash(key));
        // cout << i << endl;
        if (i == -1) {
            resize();
            return remove(key);
        } else if (map[i].first != -1) {
            // cout << "removed " << key << " holding value " << map[i].second << " #" << i << endl;
            map[i] = {-2, 0}; // Sentinel value
            --length;
        }
    }
private:
    int probe(int key, int initialIdx) {
        int currentIdx {initialIdx};

        do {
            if (map[currentIdx].first == -1) return currentIdx;
            if (map[currentIdx].first == key) return currentIdx;
            currentIdx = (currentIdx + 1) % map.size();
        } while (currentIdx != initialIdx);

        return -1; // Hash table is full
    }

    int hash(int key) {
        return key % map.size();
    }

    void resize() {
        // cout << "resizing" << endl;
        vector<pair<int, int>> items;
        for (int i {0}; i < map.size(); ++i) {
            if ((map[i].first != -1 && map[i].first != -2)) {
                items.push_back((map[i]));
                map[i] = {-1, 0};
            }
        }

        // cout << "checking " << items.size() << " " << length << endl;

        length = 0;
        map.resize(map.size() * 2, {-1, 0});
        for (auto [key, value] : items) {
            put(key, value);
        }
        // cout << "resizing completed" << endl;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

