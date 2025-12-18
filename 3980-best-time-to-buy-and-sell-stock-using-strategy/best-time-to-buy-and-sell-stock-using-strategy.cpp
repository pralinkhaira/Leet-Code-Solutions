class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;
        
        // Calculate base profit without any modification
        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += (long long)strategy[i] * prices[i];
        }
        
        // Compute prefix sums for prices and strategy*prices
        vector<long long> prefixPrice(n + 1, 0);
        vector<long long> prefixProfit(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefixPrice[i + 1] = prefixPrice[i] + prices[i];
            prefixProfit[i + 1] = prefixProfit[i] + (long long)strategy[i] * prices[i];
        }
        
        long long maxDelta = 0;
        
        // Try each possible k-length segment
        for (int i = 0; i <= n - k; i++) {
            // Original contribution from this segment
            long long originalContribution = prefixProfit[i + k] - prefixProfit[i];
            
            // After modification:
            // First k/2 become 0: contribute 0
            // Last k/2 become 1: contribute sum of their prices
            long long lastHalfSum = prefixPrice[i + k] - prefixPrice[i + half];
            long long newContribution = lastHalfSum;
            
            long long delta = newContribution - originalContribution;
            maxDelta = max(maxDelta, delta);
        }
        
        return baseProfit + maxDelta;
    }
};