class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int maxGap = 0;

        for (int i = 0; n > 0; i++) {
            if (n & 1) {
                if (last != -1)
                    maxGap = max(maxGap, i - last);
                last = i;
            }
            n >>= 1;
        }

        return maxGap;
    }
};