# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: 'TreeNode') -> 'TreeNode':
        def dfs(node):
            # Returns (max_depth, lowest_common_ancestor_of_deepest_nodes)
            if not node:
                return (0, None)
            
            left_depth, left_node = dfs(node.left)
            right_depth, right_node = dfs(node.right)
            
            # Maximum depth from this node
            max_depth = max(left_depth, right_depth) + 1
            
            # If both sides have same depth, current node is the answer
            if left_depth == right_depth:
                return (max_depth, node)
            # If left is deeper, propagate left's answer
            elif left_depth > right_depth:
                return (max_depth, left_node)
            # If right is deeper, propagate right's answer
            else:
                return (max_depth, right_node)
        
        _, result = dfs(root)
        return result