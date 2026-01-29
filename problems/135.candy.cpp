/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 * 
 * NOTE: A one-pass O(1) space sol exists
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;

        vector<int> childrenCandies(ratings.size(), -1);

        if (ratings[0] <= ratings[1]) childrenCandies[0] = 1;
        for (int i {1}; i < ratings.size() - 1; ++i) {
            if (ratings[i - 1] >= ratings[i] && ratings[i] <= ratings[i + 1]) {
                childrenCandies[i] = 1;
            }
        }
        if (ratings[ratings.size() - 2] >= ratings.back()) childrenCandies[ratings.size() - 1] = 1;

        // for (const int x : ratings) cout << x << " ";
        // cout << endl;
        // for (const int x : childrenCandies) cout << x << " ";
        // cout << endl;

        fillCandies(childrenCandies, ratings);
        reverse(childrenCandies.begin(), childrenCandies.end());
        reverse(ratings.begin(), ratings.end());
        fillCandies(childrenCandies, ratings);

        // reverse(childrenCandies.begin(), childrenCandies.end());
        // for (const int x : childrenCandies) cout << x << " ";

        return accumulate(childrenCandies.begin(), childrenCandies.end(), 0);
    }
private:
    void fillCandies(vector<int>& childrenCandies, vector<int>& ratings) {
        int currCandies {-1};
        for (int i {0}; i < childrenCandies.size(); ++i) {
            if (childrenCandies[i] == 1) {
                currCandies = 1;
                continue;
            }
            if (currCandies == -1) continue;

            if (childrenCandies[i] == -1) {
                if (ratings[i - 1] < ratings[i]) {
                    childrenCandies[i] = ++currCandies;
                } else {
                    currCandies = -1;
                }
            } else if (ratings[i - 1] < ratings[i] && currCandies >= childrenCandies[i]) {
                childrenCandies[i] = ++currCandies;
            } else {
                // Don't do anything, keep this already set maximum
                // i.e. currCandies < childrenCandies[i]
                currCandies = -1;
            }
        }
    }
};
// @lc code=end

