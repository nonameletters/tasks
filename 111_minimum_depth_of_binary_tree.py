# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def move(self, root: Optional[TreeNode], depth: int) -> int:
        if root is None:
            return depth

        if (root.left is None and root.right is None):
            return depth + 1
        
        lr = self.move(root.left, depth + 1)
        rr = self.move(root.right, depth + 1)

        if (root.left is None):
            return rr
            
        if (root.right is None):
            return lr

        return min(lr, rr)

    def minDepth(self, root: Optional[TreeNode]) -> int:
        return self.move(root, 0)
