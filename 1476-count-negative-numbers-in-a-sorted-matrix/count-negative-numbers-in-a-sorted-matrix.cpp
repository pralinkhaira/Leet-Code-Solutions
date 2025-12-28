class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // Start from top-right corner
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                // If current element is negative, 
                // all elements below it in this column are also negative
                count += (m - row);
                col--;
            } else {
                // If current element is non-negative, move down
                row++;
            }
        }
        
        return count;
    }
};