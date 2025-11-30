class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Calculate total sum and remainder
        long long total = 0;
        for (int num : nums) {
            total += num;
        }
        
        int remainder = total % p;
        
        // If already divisible, return 0
        if (remainder == 0) {
            return 0;
        }
        
        // We need to find a subarray with sum % p == remainder
        // Use prefix sum technique
        unordered_map<int, int> lastSeen; // remainder -> last index
        lastSeen[0] = -1; // Base case: prefix sum 0 at index -1
        
        long long prefixSum = 0;
        int minLen = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currRemainder = prefixSum % p;
            
            // We need to find: (prefixSum - subarray) % p == 0
            // Which means: subarray % p == prefixSum % p
            // We're looking for a prefix with remainder == (currRemainder - remainder + p) % p
            int targetRemainder = (currRemainder - remainder + p) % p;
            
            if (lastSeen.find(targetRemainder) != lastSeen.end()) {
                int subarrayLen = i - lastSeen[targetRemainder];
                // Make sure we don't remove the whole array
                if (subarrayLen < (int)nums.size()) {
                    minLen = min(minLen, subarrayLen);
                }
            }
            
            lastSeen[currRemainder] = i;
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
};