class Solution:
    def move(self, root:Optional[TreeNode], curSum: int, targetSum:int) -> bool:
        if not root:
            return False
        
        if (root.left is None) and (root.right is None):
            if curSum + root.val == targetSum:
                return True
            else:
                return False

        # This condition is good when targetSum and val > 0
        # while targetSum and val could be less than 0. Next 
        # statement will follow to wrong answer
        #if curSum >= targetSum: 
        #    return False
        
        lr = self.move(root.left, curSum + root.val, targetSum)
        rr = self.move(root.right, curSum + root.val, targetSum)

        return lr or rr

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        res = self.move(root, 0, targetSum)
        return res
