class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, 0)
    
    def dfs(self, root, sum):
        if not root:
            return 0
        sum = sum * 10 + root.val
        if not root.left and not root.right:
            return sum
        return self.dfs(root.left, sum) + self.dfs(root.right, sum)