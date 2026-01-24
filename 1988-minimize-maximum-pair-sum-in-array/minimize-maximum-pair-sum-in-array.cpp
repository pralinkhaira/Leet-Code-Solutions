class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSum = 0;
        int n = nums.size();
        
        // Pair smallest with largest
        for (int i = 0; i < n / 2; i++) {
            int currentSum = nums[i] + nums[n - 1 - i];
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};