class Solution:
    ans = []

    def move(self, root: Optional[TreeNode], curSum: int, inList: [int]) -> List[List[int]]:
        if not root:
            return
        
        if (root.left is None) and (root.right is None):
            if curSum == root.val:
                self.ans.append(inList + [root.val])
            return

        
        lr = self.move(root.left, curSum - root.val, inList + [root.val])
        rr = self.move(root.right, curSum - root.val, inList + [root.val])


    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.ans = []
        self.move(root, targetSum, [])
        return self.ans
