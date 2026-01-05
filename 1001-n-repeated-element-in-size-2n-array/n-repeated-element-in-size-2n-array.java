class Solution {
    public int repeatedNTimes(int[] nums) {
        boolean[] seen = new boolean[10001];
        
        for (int num : nums) {
            if (seen[num]) {
                return num;
            }
            seen[num] = true;
        }
        
        return 0;
    }
}