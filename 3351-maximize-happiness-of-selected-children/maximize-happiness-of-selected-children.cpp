class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long total = 0;
        for (int i = 0; i < k; i++) {
            // Each selected child loses happiness by 'i' (number of previous selections)
            // But happiness can't go below 0
            long long currentHappiness = max(0, happiness[i] - i);
            total += currentHappiness;
        }
        
        return total;
    }
};