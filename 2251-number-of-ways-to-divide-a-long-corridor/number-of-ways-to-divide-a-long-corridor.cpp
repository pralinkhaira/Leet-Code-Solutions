class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        int n = corridor.length();
        
        // Count total seats
        int seatCount = 0;
        for (char c : corridor) {
            if (c == 'S') seatCount++;
        }
        
        // If odd number of seats, no valid division
        if (seatCount % 2 == 1) return 0;
        
        // If less than 2 seats, can't form a section
        if (seatCount < 2) return 0;
        
        long long result = 1;
        int seatsInSection = 0;
        
        // Find gaps between consecutive seat pairs
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                seatsInSection++;
                
                // When we complete a pair of seats
                if (seatsInSection % 2 == 0) {
                    // Count plants after the second seat of this pair
                    long long gap = 0;
                    int j = i + 1;
                    while (j < n && corridor[j] == 'P') {
                        gap++;
                        j++;
                    }
                    
                    // If this is not the last pair, multiply by (gap + 1)
                    if (j < n) { // not end of corridor
                        result = (result * (gap + 1)) % MOD;
                    }
                }
            }
        }
        
        return result;
    }
};