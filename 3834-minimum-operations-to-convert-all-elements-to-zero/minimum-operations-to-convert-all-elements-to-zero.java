class Solution {
    private void groupIdx(List<List<Integer>> groups, int[] vals) {
        int pos = 0;
        int n = vals.length;
        while (pos < n) {
            if (vals[pos] > 0) {
                groups.get(vals[pos]).add(pos);
            }
            pos++;
        }
    }

    private int countOperations(List<Integer> positions, FenwickTree tracker) {
        int ops = 0;
        int lastPos = -2;
        int it = 0;
        int m = positions.size();
        while (it < m) {
            int curr = positions.get(it);
            if (lastPos == -2 || tracker.rangeCount(lastPos + 1, curr - 1) > 0) {
                ops++;
            }
            lastPos = curr;
            it++;
        }
        int j = 0;
        while (j < m) {
            tracker.mark(positions.get(j), 1);
            j++;
        }
        return ops;
    }

    public int minOperations(int[] nums) {
        int n = nums.length;
        int peak = 0, idx = 0;
        while (idx < n) {
            if (nums[idx] > peak) {
                peak = nums[idx];
            }
            idx++;
        }

        List<List<Integer>> groups = new ArrayList<>();
        for (int i = 0; i <= peak + 5; i++) {
            groups.add(new ArrayList<>());
        }
        groupIdx(groups, nums);

        FenwickTree zeroTracker = new FenwickTree(n);
        int i = 0;
        while (i < n) {
            if (nums[i] == 0) {
                zeroTracker.mark(i, 1);
            }
            i++;
        }

        int res = 0;
        int val = 1;
        while (val <= peak) {
            if (!groups.get(val).isEmpty()) {
                res += countOperations(groups.get(val), zeroTracker);
            }
            val++;
        }

        return res;
    }
}

class FenwickTree {
    private int[] BIT;
    private int len;

    public FenwickTree(int size) {
        len = size;
        BIT = new int[size + 2];
    }

    public void mark(int idx, int val) {
        idx++;
        while (idx <= len) {
            BIT[idx] += val;
            idx += (idx & -idx);
        }
    }

    public int sum(int idx) {
        idx++;
        int res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    public int rangeCount(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
}
