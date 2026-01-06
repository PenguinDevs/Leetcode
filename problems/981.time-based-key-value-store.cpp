/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> data;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto comp = [](const int timestamp, const pair<int, string>& entry) {
            return timestamp < entry.first;
        };

        auto &timestamps = data[key];
        auto lowerIt = upper_bound(timestamps.begin(), timestamps.end(), timestamp, comp);
        if (lowerIt == timestamps.begin()) return "";
        --lowerIt;

        return lowerIt->second;
    }
};

// That was stupid, problem statement didn't specify that all future timestamps
// will always be greater than the last!?!?!?
// class TimeMap {
// private:
//     unordered_map<string, map<int, string>> data;

// public:
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         data[key][timestamp] = value;
//     }
    
//     string get(string key, int timestamp) {
//         map<int, string> &timestamps = data[key];
//         auto lowerIt = timestamps.upper_bound(timestamp);
//         if (lowerIt == timestamps.begin()) return "";
//         --lowerIt;

//         return lowerIt->second;
//     }
// };

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

