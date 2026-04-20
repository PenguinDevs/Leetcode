/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        const int n = asteroids.size();
        
        stack<int> left;
        for (const int x : asteroids) {
            if (left.empty()) {
                left.push(x);
                continue;
            }

            bool isDestroyed {false};
            while (!left.empty() && left.top() > 0 && x < 0) {
                const int top {left.top()};
                if (abs(top) <= abs(x)) {
                    left.pop();
                }

                if (abs(top) >= abs(x)) {
                    isDestroyed = true;
                    break;
                }
            }

            if (!isDestroyed) left.push(x);
        }

        vector<int> out(left.size());
        while (!left.empty()) {
            const int x {left.top()};
            left.pop();
            out[left.size()] = x;
        }

        return out;
    }
};
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         const int n = asteroids.size();
//         vector<int> rightAsteroids;
//         rightAsteroids.reserve(n);

//         for (int i {0}; i < n; ++i) {
//             if (i < n - 1 && asteroids[i] >= -asteroids[i + 1] && asteroids[i + 1] < 0) {
//                 if (asteroids[i] != -asteroids[i + 1]) rightAsteroids.push_back(asteroids[i]);
//                 ++i;
//             } else {
//                 rightAsteroids.push_back(asteroids[i]);
//             }
//         }

//         const int m = rightAsteroids.size();
//         vector<int> leftAsteroids;
//         leftAsteroids.reserve(m);
//         for (int i {m - 1}; i >= 0; --i) {
//             if (i < n - 1 && asteroids[i] >= -asteroids[i + 1] && asteroids[i + 1] < 0) {
//                 if (asteroids[i] != -asteroids[i + 1]) rightAsteroids.push_back(asteroids[i]);
//                 --i;
//             } else {
//                 rightAsteroids.push_back(asteroids[i]);
//             }
//         }

//         for (const int x : rightAsteroids) cout << x << ' ';

//         return rightAsteroids;
//     }
// };
// @lc code=end

