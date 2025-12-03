/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyHashSet {
public:
    static constexpr double LOAD_FACTOR_THRESH {0.75};
    static constexpr int INITIAL_CAPACITY {16};

    vector<int> map;
    int length {0};

    MyHashSet() {
        map.resize(INITIAL_CAPACITY, -1);
    }
    
    void add(int key) {
        int i = probe(key, hash(key));
        // cout << i << endl;
        if (i == -1) {
            resize();
            return add(key);
        } else {
            // cout << "assigning " << value << " at " << key << " #" << i << endl;
            if (map[i] == -1) {
                map[i] = key;
                ++length;
                
                if (length > map.size() * LOAD_FACTOR_THRESH) {
                    resize();
                }
            } else {
                map[i] = key;
            }
        }
    }
    
    void remove(int key) {
        int i = probe(key, hash(key));
        // cout << i << endl;
        if (i == -1) {
            resize();
            return remove(key);
        } else if (map[i] != -1) {
            // cout << "removed " << key << " holding value " << map[i].second << " #" << i << endl;
            map[i] = -2; // Sentinel value
            --length;
        }
    }
    
    bool contains(int key) {
        int i = probe(key, hash(key));
        // cout << i << endl;
        if (i == -1) {
            resize();
            return contains(key);
        } else if (map[i] == key) {
            // cout << "got " << map[i].second << " at " << map[i].first << " #" << i << endl;
            return true;
        } else {
            return false;
        }
    }
private:
    int probe(int key, int initialIdx) {
        int currentIdx {initialIdx};

        do {
            if (map[currentIdx] == -1) return currentIdx;
            if (map[currentIdx] == key) return currentIdx;
            currentIdx = (currentIdx + 1) % map.size();
        } while (currentIdx != initialIdx);

        return -1; // Hash table is full
    }

    int hash(int key) {
        return key % map.size();
    }

    void resize() {
        // cout << "resizing" << endl;
        vector<int> items;
        for (int i {0}; i < map.size(); ++i) {
            if ((map[i] != -1 && map[i] != -2)) {
                items.push_back(map[i]);
                map[i] = -1;
            }
        }

        // cout << "checking " << items.size() << " " << length << endl;

        length = 0;
        map.resize(map.size() * 2, -1);
        for (int& key : items) {
            add(key);
        }
        // cout << "resizing completed" << endl;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

