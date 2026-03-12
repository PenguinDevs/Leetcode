/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class DetectSquares {
public:
    vector<vector<int>> grid;
    vector<vector<int>> rowCols;
    static const int n {1001};
    DetectSquares() : grid(n, vector<int>(n)), rowCols(n) {
        
    }
    
    void add(vector<int> point) {
        ++grid[point[1]][point[0]];
        rowCols[point[1]].push_back(point[0]);
    }
    
    int count(vector<int> point) {
        int count {0};

        for (const int j : rowCols[point[1]]) {
            const int width = abs(point[0] - j);
            if (width == 0) continue;
            for (const int i : {point[1] + width, point[1] - width}) {
                if (i < 0) continue;
                if (i >= n) continue;
                if (grid[i][j] && grid[i][point[0]]) {
                    count += grid[i][point[0]] * grid[i][j];
                }
            }
        }

        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

