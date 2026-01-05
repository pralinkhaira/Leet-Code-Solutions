class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;
        
        // Traverse the matrix
        for(auto& row : matrix) {
            for(int num : row) {
                sum += abs(num);
                if(num < 0) negCount++;
                minAbs = min(minAbs, abs(num));
            }
        }
        
        // If odd number of negatives, we have to keep one negative
        // So we subtract twice the smallest absolute value
        if(negCount % 2 == 1) {
            sum -= 2LL * minAbs;
        }
        
        return sum;
    }
};