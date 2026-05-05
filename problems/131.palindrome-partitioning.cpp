/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        vector<vector<bool>> palindromes(n, vector<bool>(n));
        for (int k {1}; k <= n; ++k) {
            for (int l {0}; l < n - k + 1; ++l) {
                const int r = l + k - 1;
                if (k == 1) {
                    palindromes[l][r] = true;
                } else if (k == 2) {
                    palindromes[l][r] = s[l] == s[r];
                } else {
                    palindromes[l][r] = palindromes[l + 1][r - 1] && (s[l] == s[r]);
                }
            }
        }

        // for (const auto& row : palindromes) {
        //     for (const int x : row) cout << x << " ";
        //     cout << '\n';
        // }
        
        vector<vector<string>> partitions;
        for (int r {0}; r < n; ++r) {
            if (palindromes[0][r]) {
                vector<string> partition;
                partition.push_back(s.substr(0, r + 1));
                buildPartitions(palindromes, partitions, partition, s, r + 1);
            }
        }
        
        return partitions;
    }
private:
    void buildPartitions(
        vector<vector<bool>>& palindromes,
        vector<vector<string>>& partitions,
        vector<string>& currPartition,
        string& s,
        int l
    ) {
        const int n = s.size();
        
        if (l >= n) partitions.push_back(currPartition);

        for (int r {l}; r < n; ++r) {
            if (palindromes[l][r]) {
                currPartition.push_back(s.substr(l, r - l + 1));
                buildPartitions(palindromes, partitions, currPartition, s, r + 1);
                currPartition.pop_back();
            }
        }
    }
};
// @lc code=end

