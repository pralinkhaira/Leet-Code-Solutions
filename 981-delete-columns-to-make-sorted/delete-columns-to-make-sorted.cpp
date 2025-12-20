class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int cols = strs[0].length();
        
        // Check each column
        for (int col = 0; col < cols; col++) {
            // Check if this column is sorted lexicographically
            for (int row = 1; row < strs.size(); row++) {
                if (strs[row][col] < strs[row-1][col]) {
                    count++;
                    break;
                }
            }
        }
        
        return count;
    }
};