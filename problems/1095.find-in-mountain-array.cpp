/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

#include <bits/stdc++.h>
using namespace std;

class MountainArray {
  public:
    int get(int index);
    int length();
};

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    vector<int> cache;
    vector<int> storedIdxs;
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int n = mountainArr.length();
        storedIdxs.clear();
        cache.clear();
        cache.resize(n, -1);

        int peakIdx;
        {
            int l {0};
            int r {n - 1};
            while (l < r) {
                int mid = l + (r - l) / 2;
                // cout << mid << '\n';
                if (cachedGet(mid, mountainArr) < cachedGet(mid + 1, mountainArr)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            peakIdx = l;
        }

        sort(storedIdxs.begin(), storedIdxs.end());
        // for (int x : storedIdxs) cout << x << " "; cout << '\n';
        const auto [lowerLeft, lowerRight] = findBoundingIdxs(target, 0, peakIdx);
        // cout << lowerLeft << " "  << lowerRight << '\n';
        const auto [upperLeft, upperRight] = findBoundingIdxs(target, lowerRight, peakIdx);
        // cout << "and again " << upperLeft << " "  << upperRight << '\n';

        {
            int l {lowerLeft};
            int r {lowerRight};
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (cachedGet(mid, mountainArr) < target) {
                    l = mid + 1;
                } else if (cachedGet(mid, mountainArr) > target) {
                    r = mid;
                } else {
                    return mid;
                }
            }
        }

        {
            int l {upperLeft};
            int r {upperRight};
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (cachedGet(mid, mountainArr) > target) {
                    l = mid + 1;
                } else if (cachedGet(mid, mountainArr) < target) {
                    r = mid;
                } else {
                    return mid;
                }
            }
        }

        // cout << cache[peakIdx] << '\n';

        return -1;
    }
private:
    int cachedGet(int i, MountainArray &mountainArr) {
        if (cache[i] != -1) return cache[i];
        storedIdxs.push_back(i);
        return cache[i] = mountainArr.get(i);
    }

    pair<int, int> findBoundingIdxs(int target, int startIdx, int peakIdx) {
        if (startIdx == 0 && target <= cache[storedIdxs.front()]) {
            return {0, storedIdxs.front() + 1};
        } else if (startIdx >= peakIdx && target <= cache[storedIdxs.back()]) {
            return {storedIdxs.back(), cache.size() - 1 + 1};
        }
        int leftPeakIdx;
        int rightPeakIdx;
        for (int i {1}; i < storedIdxs.size(); ++i) {
            int leftIdx {storedIdxs[i - 1]};
            int rightIdx {storedIdxs[i]};
            if (leftIdx < startIdx) continue;

            // cout << "found " << cache[leftIdx] << " " << cache[rightIdx] << '\n';
            if (rightIdx <= peakIdx && cache[leftIdx] <= target && target <= cache[rightIdx]) return {leftIdx, rightIdx + 1};
            if (leftIdx >= peakIdx && cache[leftIdx] >= target && target >= cache[rightIdx]) return {leftIdx, rightIdx + 1};
        
            if (peakIdx == rightIdx) {
                leftPeakIdx = leftIdx;
                rightIdx = storedIdxs[i + 1];
            }
        }
        return {leftPeakIdx, rightPeakIdx + 1};
    }
};
// @lc code=end

