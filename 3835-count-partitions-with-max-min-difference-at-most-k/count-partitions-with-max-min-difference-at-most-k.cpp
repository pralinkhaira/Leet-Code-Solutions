class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = (int)nums.size();

        int dp[n + 1];
        int psum[n + 1];
        
        dp[0]   = 1;
        psum[0] = 1;

        //increasing
        deque<int> inc;
        //decreasing
        deque<int> dec;

        for(int r = 0, l = 0; r < n; r ++){
            while(!inc.empty() && nums[inc.back()] >= nums[r]){
                inc.pop_back();
            }
            inc.push_back(r);
            while(!dec.empty() && nums[dec.back()] <= nums[r]){
                dec.pop_back();
            }
            dec.push_back(r);
            while(!inc.empty() && !dec.empty()){
                if(nums[dec.front()] - nums[inc.front()] > k){
                    if(inc.front() == l) inc.pop_front();
                    if(dec.front() == l) dec.pop_front();
                    l += 1;
                }
                else{
                    break;
                }
            }
            int rangedp = psum[r];
            if(l > 0) rangedp -= psum[l - 1];
            rangedp %= mod;
            if(rangedp < 0) rangedp += mod;

            dp[r + 1]   = rangedp;
            psum[r + 1] = (psum[r] + dp[r + 1]) % mod;
        }
        return dp[n];
    }
};