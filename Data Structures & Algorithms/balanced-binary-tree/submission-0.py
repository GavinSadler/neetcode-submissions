# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        self.isBalanced = True

        def height(n: Optional[TreeNode]) -> int:

            if n is None:
                return 0

            hl = height(n.left)
            hr = height(n.right)

            # print(n.val, hl, hr)

            if hl >= hr + 2 or hr >= hl + 2:
                self.isBalanced = False

            return max(hl, hr) + 1
        
        height(root)
        
        return self.isBalanced
