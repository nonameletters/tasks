class Solution:
    def move(self, root: Optional[TreeNode]) -> [bool, int]:
        if root is None:
            return [True, 0]

        lr = self.move(root.left)
        lr[1] += 1
        rr = self.move(root.right)
        rr[1] += 1

        if (lr[0] and rr[0]) and (abs(lr[1] - rr[1]) <= 1):
            return [True, max(lr[1], rr[1])]
        else:
            return [False, max(lr[1], rr[1])]


    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        lr = self.move(root.left)
        rr = self.move(root.right)

        if (lr[0] and rr[0]) and (abs(lr[1] - rr[1]) <= 1):
            return True
        else:
            return False
