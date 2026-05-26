# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        if root is None:
            return []

        out = [root.val]
        
        q = []

        if root.left:
            q.append(root.left)
            
        if root.right:
            q.append(root.right)

        while len(q):

            level = list(q)
            q = []

            for i, node in enumerate(level):

                if node.left:
                    q.append(node.left)
                
                if node.right:
                    q.append(node.right)
            
                if i == len(level) - 1:
                    out.append(node.val)
            
        return out
