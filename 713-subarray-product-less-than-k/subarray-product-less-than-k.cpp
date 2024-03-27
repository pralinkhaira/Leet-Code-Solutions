class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        int l = 0;
        int p = 1;
        int res = 0;
        for (int r = 0; r < nums.size(); r++) {
            p *= nums[r];
            while (p >= k)
                p /= nums[l++];
            res += r - l + 1;
        }

        return res;
    }
};