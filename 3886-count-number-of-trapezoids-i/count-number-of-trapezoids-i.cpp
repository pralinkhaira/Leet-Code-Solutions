class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;
        
        // Group points by y-coordinate
        map<int, int> yCount;
        for (auto& p : points) {
            yCount[p[1]]++;
        }
        
        // Calculate number of segments at each y-level
        vector<long long> segments;
        for (auto& [y, count] : yCount) {
            // Number of ways to choose 2 points from count points
            long long seg = (long long)count * (count - 1) / 2;
            segments.push_back(seg);
        }
        
        // Calculate sum and sum of squares
        long long sum = 0;
        long long squareSum = 0;
        
        for (long long seg : segments) {
            sum = (sum + seg) % MOD;
            squareSum = (squareSum + seg * seg) % MOD;
        }
        
        // Using formula: sum of pairs = (sum^2 - squareSum) / 2
        long long ans = ((sum * sum) % MOD - squareSum + MOD) % MOD;
        ans = (ans * 500000004) % MOD; // multiply by modular inverse of 2
        
        return ans;
    }
};