class Solution {
public:
    int smallestNumber(unsigned n) {
        return bit_ceil(n+1)-1;
    }
};