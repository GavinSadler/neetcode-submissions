# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        maxD = 0

        def dfs(n: Optional[TreeNode]):
            nonlocal maxD

            if n is None:
                return

            dfs(n.left)
            dfs(n.right)

            d = 0

            if n.left:
                d += 1 + height(n.left)
                
            if n.right:
                d += 1 + height(n.right)
            
            maxD = max(maxD, d)


        def height(n: Optional[TreeNode]) -> int:
            if n is None or (n.left is None and n.right is None):
                return 0
            
            return max(height(n.left), height(n.right)) + 1

        dfs(root)

        return maxD