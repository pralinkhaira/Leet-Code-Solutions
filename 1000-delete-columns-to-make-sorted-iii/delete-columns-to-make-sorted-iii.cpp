class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        
        // dp[j] = max columns we can keep ending at column j
        vector<int> dp(m, 1);
        
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                // Check if we can add column j after keeping column k
                bool canAdd = true;
                for (int i = 0; i < n; i++) {
                    if (strs[i][j] < strs[i][k]) {
                        canAdd = false;
                        break;
                    }
                }
                if (canAdd) {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }
        }
        
        int maxKeep = *max_element(dp.begin(), dp.end());
        return m - maxKeep;
    }
};