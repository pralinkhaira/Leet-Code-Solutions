class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long result = LLONG_MIN;
        long long preSum = nums[0];
        int l = 0;
        int p = 0;
        int q = 0;

        for (int r = 1; r < n; r++) {
            preSum += nums[r];

            //--CASE 1:-- (equal)
            //'q' to 'r' must be strictly increasing.
            // If two consecutive values are equal, strict increase/decrease is broken.
            // That means no trionic structure can exist including this pair.
            // So we reset the window completely and start fresh from r.
            if (nums[r - 1] == nums[r]) {
                l = r;
                preSum = nums[r];
            }

            //--CASE 2:-- ↘️
            // Now if slope is downhill
            // This is not the final desired slope (we want q→r increasing),
            // but this is still useful because it may help us detect a PEAK.
            else if (nums[r - 1] > nums[r]) { //this r-1 might be a peak

                // so lets check it (if 'r-1' is greater than both 'r-2' and 'r, it is a peak)
                if (r > 1 && nums[r - 2] < nums[r - 1]) {
                    p = r - 1; //yes, we found one local peak (marked it)

                    // okay, now since we just marked 'p'
                    // we are structurally in a situation like:
                    // l → q → p → r   (WRONG ORDER)
                    //
                    // But the required order must be:
                    // l → p → q → r
                    //
                    // note - ('l' must come before 'p')
                    // and we have just marked 'p'
                    //
                    // This also means any previously found 'q' (valley) must come AFTER this 'p'.
                    // Therefore, everything before the old 'q' is structurally invalid.
                    //
                    // So we shrink the window from the left until l == q,
                    // because only q (if it exists) can still act as a future valid 'l'.
                    //
                    //So after this loop finishes, our 'l' will be at same point as 'q'.
                    //
                    //---(see explanation diagram 1 below )---
                    //
                    while (l < q) preSum -= nums[l++];

                    // okay, now the 'l' and 'p' are in correct position
                    // But we can still optimize them, for the maximum sum
                    //
                    // now we since know that 'p-1' is the last value possible in our order for 'l',
                    // we simply trim out the negative values before 'p-1'.
                    //
                    // Why?
                    //
                    // because Between l and p, we only need a strictly increasing slope.
                    // which we already have
                    // Negative numbers before p do NOT help structure,
                    // and they reduce the total sum.
                    //
                    // ---(see explanation diagram 2 below)---
                    //
                    while (l < p - 1 && nums[l] < 0) preSum -= nums[l++];
                }
            }

            //--CASE 3:-- ↗️
            // when 'r-1' is smaller than 'r' → strictly increasing
            // Slope is uphill
            // This is exactly what we want for the final segment (q → r).
            else {
                // Check for valley:
                // (if 'r-1' is smaller than both 'r-2' and 'r')
                if (r > 1 && nums[r - 2] > nums[r - 1]) q = r - 1; // found valley point

                // Now if the structure aligns as:
                // l < p < q < r
                // then a valid trionic subarray exists.
                if (l < p && p < q) result = max(result, preSum);
            }
        }

        return result;
    }
};