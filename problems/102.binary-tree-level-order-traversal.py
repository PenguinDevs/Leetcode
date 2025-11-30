#
# @lc app=leetcode id=102 lang=python3
#
# [102] Binary Tree Level Order Traversal
#

from typing import Optional, List, Tuple
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        output: List[List[int]] = []

        if not root:
            return output
        
        q = deque[Tuple[int, TreeNode]]()
        q.append((0, root))
        while (len(q) > 0):
            layer, current = q.pop()

            if layer >= len(output):
                output.append([])

            output[layer].append(current.val)

            if current.right:
                q.append((layer + 1, current.right))
            if current.left:
                q.append((layer + 1, current.left))

        return output

# @lc code=end

