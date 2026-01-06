/**
 * Definition for a binary tree node.
 */
class Solution {
    public int maxLevelSum(TreeNode root) {
        if (root == null) return -1;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        long maxSum = Long.MIN_VALUE;
        int maxLevel = 1;
        int currentLevel = 1;
        
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            long levelSum = 0;
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                levelSum += node.val;
                
                // Add children to queue for next level
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            
            // Update max sum and corresponding level
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }
            
            currentLevel++;
        }
        
        return maxLevel;
    }
}