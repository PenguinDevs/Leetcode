/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int charIndex) {
        if (charIndex == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[charIndex]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool found = dfs(board, word, i + 1, j, charIndex + 1) ||  // down
                     dfs(board, word, i - 1, j, charIndex + 1) ||  // up
                     dfs(board, word, i, j + 1, charIndex + 1) ||  // right
                     dfs(board, word, i, j - 1, charIndex + 1);    // left
        
        board[i][j] = temp;
        
        return found;
    }
};
// @lc code=end

