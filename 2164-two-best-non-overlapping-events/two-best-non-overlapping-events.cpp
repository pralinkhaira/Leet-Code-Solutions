class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int n = events.size();
        // dp[i][j] = max value using first i events with at most j events selected
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2; j++) {
                // Option 1: Don't take event i-1
                dp[i][j] = dp[i-1][j];
                
                if (j > 0) {
                    int val = events[i-1][2];
                    
                    // Find the latest event that ends before current event starts
                    int left = 0, right = i - 2;
                    int idx = -1;
                    
                    while (left <= right) {
                        int mid = (left + right) / 2;
                        if (events[mid][1] < events[i-1][0]) {
                            idx = mid;
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                    
                    if (idx != -1) {
                        dp[i][j] = max(dp[i][j], val + dp[idx + 1][j - 1]);
                    } else {
                        dp[i][j] = max(dp[i][j], val);
                    }
                }
            }
        }
        
        return dp[n][2];
    }
};