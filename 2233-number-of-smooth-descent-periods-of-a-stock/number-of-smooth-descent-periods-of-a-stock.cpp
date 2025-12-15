class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 0;
        long long length = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0 || prices[i] != prices[i-1] - 1) {
                // Start a new descent period
                length = 1;
            } else {
                // Continue the descent period
                length++;
            }
            // Add the number of smooth descent periods ending at i
            count += length;
        }
        
        return count;
    }
};