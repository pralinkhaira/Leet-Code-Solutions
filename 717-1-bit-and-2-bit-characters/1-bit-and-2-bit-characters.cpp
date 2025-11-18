class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bits.pop_back();
        int n = bits.size();

        // Short-circuit:
        if (n == 0 || bits.back() == 0)
            return true;

        // Count consecutive 1s from the end (trailing ones)
        int ones = 0;        
        for (int i = n - 1; i >= 0 && bits[i] == 1; i--)
            ones++;

        // - Even ones count → last bit is a 1-bit character
        // - Odd ones count  → last bit is part of a 2-bit character
        return ~ones & 1;
    }
};
