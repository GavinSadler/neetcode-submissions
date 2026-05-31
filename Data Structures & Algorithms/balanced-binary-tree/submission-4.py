# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        # def dfs_recursive(n: Optional[TreeNode]):

        #     if not n:
        #         return

        #     dfs_recursive(n.left)
        #     dfs_recursive(n.right)
        
        #     print(n.val)

        # print("dfs-recursive")
        # dfs_recursive(root)


        # def dfs_iterative(root: Optional[TreeNode]):
        #     if not root:
        #         return

        #     visited = set()
        #     stack = [root]

        #     while stack:
        #         top = stack[-1]

        #         if top.left and top.left not in visited:
        #             stack.append(top.left)
        #         elif top.right and top.right not in visited:
        #             stack.append(top.right)
        #         else:
        #             print(top.val)
        #             visited.add(top)
        #             stack.pop()
            
        # print("dfs-itterative")
        # dfs_iterative(root)

        # def heightBalanced_iterative(root: Optional[TreeNode]):
        #     if not root:
        #         return True

        #     heights = {}
        #     stack = [root]

        #     while stack:
        #         top = stack[-1]

        #         if top.left and top.left not in heights:
        #             stack.append(top.left)
        #         elif top.right and top.right not in heights:
        #             stack.append(top.right)
        #         else:
        #             lh = heights[top.left] if top.left else 0
        #             rh = heights[top.right] if top.right else 0

        #             if abs(lh - rh) > 1:
        #                 return False

        #             heights[top] = max(lh, rh) + 1

        #             stack.pop()
            
        #     return True

        # return heightBalanced_iterative(root)
        
        def heightBalanced_recursive(root: Optional[TreeNode]):
            if not root:
                return 0

            lh = heightBalanced_recursive(root.left)
            rh = heightBalanced_recursive(root.right)

            if abs(lh - rh) > 1 or lh == -1 or rh == -1:
                return -1

            return max(lh, rh) + 1


        return heightBalanced_recursive(root) is not -1
