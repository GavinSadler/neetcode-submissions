# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        self.maxD = 0

        def dfs(n: Optional[TreeNode]):
            if not n:
                return 0

            left_h = dfs(n.left)
            right_h = dfs(n.right)

            self.maxD = max(self.maxD, left_h + right_h)
            
            return max(left_h, right_h) + 1

        dfs(root)

        return self.maxD