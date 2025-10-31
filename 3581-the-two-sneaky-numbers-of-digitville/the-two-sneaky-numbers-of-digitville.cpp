class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size() - 2;

        for (int num : nums) XOR ^= num;            
        for (int i = 0; i < n; i++) XOR ^= i;
        //for (int i = 0; i < n; i++) XOR ^= nums[i] ^ (i < n ? i : 0); //single-pass

        int diffBit = XOR & -XOR;

        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & diffBit) == 0) a ^= num;
            else b ^= num;
        }
        for (int i = 0; i < n; i++) {
            if ((i & diffBit) == 0) a ^= i;
            else b ^= i;
        }

        return {a, b};
    }
};