/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> currTriplet(3);

        for (const auto& triplet : triplets) {
            bool isValid {true};
            bool hasTarget {false};
            for (int i {0}; i < triplet.size(); ++i) {
                if (triplet[i] > target[i]) {
                    isValid = false;
                } else if (triplet[i] == target[i]) {
                    hasTarget = true;
                }
            }
            if (!isValid || !hasTarget) continue;

            applyTriplet(currTriplet, triplet);
            if (currTriplet == target) return true;
        }

        // for (const int x : currTriplet) cout << x << " ";
        // cout << endl;
        // for (const int x : target) cout << x << " ";
        // cout << endl;

        return currTriplet == target;
    }

private:
    void applyTriplet(vector<int>& u, const vector<int>& v) {
        u[0] = max(u[0], v[0]);
        u[1] = max(u[1], v[1]);
        u[2] = max(u[2], v[2]);
    }
};
// @lc code=end

