struct State {
    long long maxProfit;
    long long buyHold;
    long long sellHold;
    
    State(long long p = 0, long long b = -1e18, long long s = -1e18) 
        : maxProfit(p), buyHold(b), sellHold(s) {}
};

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        if (prices.empty()) return 0;

        vector<State> dp(k + 1, State(0, -prices[0], prices[0]));
        
        int n = prices.size();
        
        for (int day = 1; day < n; day++) {
            long long currPrice = prices[day];
            
            for (int t = k; t >= 1; t--) {
                long long prevProfit = dp[t - 1].maxProfit;
                
                dp[t].maxProfit = max({dp[t].maxProfit, 
                                       dp[t].buyHold + currPrice, 
                                       dp[t].sellHold - currPrice});
                
                dp[t].buyHold = max(dp[t].buyHold, prevProfit - currPrice);
                
                dp[t].sellHold = max(dp[t].sellHold, prevProfit + currPrice);
            }
        }
        
        return dp[k].maxProfit;
    }
};