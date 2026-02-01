class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstMin = INT_MAX, secondMin = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }
        return nums[0] + firstMin + secondMin;
    }
};