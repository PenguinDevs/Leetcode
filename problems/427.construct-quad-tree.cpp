/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

// A solution that doesn't use recursion hahahaha
// class Solution {
// public:
//     Node* construct(vector<vector<int>>& grid) {
//         // n^2 + (n/2)(n/2) + (n/4)(n/4) + (n/8)(n/8) + ... + 1
//         // n^2 +  + n^2/4 + n^2/16 + ... + 1
//         const int n = grid.size();
//         const int m = n * n * (1.0 - pow(0.25, log2(n + 1) + 1)) / (1.0 - 0.25);
//         vector<int> cells(m, -1);

//         for (int i {0}; i < n; ++i) {
//             for (int j {0}; j < n; ++j) {
//                 // cout << cells.size() << " " << i * n + j << endl;
//                 cells[i * n + j] = grid[i][j];
//             }
//         }

//         for (int k {1}; k <= log2(n); ++k) {
//             for (int i {0}; i < n / pow(2, k); ++i) {
//                 const int prevRowWidth = pow(2, log2(n) - (k - 1));
//                 const int rowWidth = pow(2, log2(n) - k);
//                 for (int j {0}; j < n / pow(2, k); ++j) {
//                     const int prevOffset = n * n * (1.0 - pow(0.25, k - 1)) / (1.0 - 0.25);
                    
//                     const int curVal {cells[prevOffset + 2 * i * prevRowWidth + 2 * j]};
//                     int areAllSame {true};
//                     // cout << "bbbbbbbb" << endl;
//                     for (int di {0}; di < 2; ++di) {
//                         for (int dj {0}; dj < 2; ++dj) {
//                             // cout << prevOffset + (2 * i + di) * prevRowWidth + 2 * j + dj << " ";
//                             const int val = cells[prevOffset + (2 * i + di) * prevRowWidth + 2 * j + dj];
//                             if (val == -1) {
//                                 areAllSame = false;
//                                 break;
//                             } else if (curVal != val) {
//                                 areAllSame = false;
//                                 break;
//                             }
//                         }
//                         // cout << endl;
//                         if (!areAllSame) break;
//                     }
//                     // cout << areAllSame << endl;
//                     if (!areAllSame) continue;

//                     const int offset = n * n * (1.0 - pow(0.25, k)) / (1.0 - 0.25);
//                     cells[offset + i * rowWidth + j] = curVal;
//                 }
//             }
//         }

//         for (int k {0}; k <= log2(n); ++k) {
//             for (int i {0}; i < n / pow(2, k); ++i) {
//                 for (int j {0}; j < n / pow(2, k); ++j) {
//                     const int offset = n * n * (1.0 - pow(0.25, k)) / (1.0 - 0.25);
//                     cout << cells[offset + i * pow(2, log2(n) - k) + j] << " ";
//                 }
//                 cout << endl;
//             }
//         }

//         vector<Node*> nodes(m);
//         nodes[m - 1] = new Node();
//         for (int k {log2(n)}; k >= 0; ++k) {
//             for (int i {0}; i < n / pow(2, k); ++i) {
//                 for (int j {0}; j < n / pow(2, k); ++j) {
//                     const int offset = n * n * (1.0 - pow(0.25, k)) / (1.0 - 0.25);
//                     const int val = cells[offset + i * pow(2, log2(n) - k) + j];
//                     if (val == -1) continue;

//                     nodes[offset + i * pow(2, log2(n) - k) + j] = new Node(val, )
//                 }
//                 cout << endl;
//             }
//         }

//         return nodes[m - 1];
//     }
// };

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructAux(grid, 0, 0, grid.size());
    }
private:
    Node* constructAux(vector<vector<int>>& grid, const int i, const int j, const int n) {
        if (n == 1) return new Node(grid[i][j], true);

        const int newSize = n / 2;

        bool allSame {true};
        const int curVal {grid[i][j]};
        for (int di {0}; di < n; ++di) {
            for (int dj {0}; dj < n; ++ dj) {
                if (grid[i + di][j + dj] != curVal) {
                    allSame = false;
                    break;
                }
            }
        }

        if (allSame) return new Node(curVal, true);

        Node* node = new Node();
        node->topLeft = constructAux(grid, i, j, newSize);
        node->topRight = constructAux(grid, i, j + newSize, newSize);
        node->bottomLeft = constructAux(grid, i + newSize, j, newSize);
        node->bottomRight = constructAux(grid, i + newSize, j + newSize, newSize);

        return node;
    }
};

// @lc code=end

