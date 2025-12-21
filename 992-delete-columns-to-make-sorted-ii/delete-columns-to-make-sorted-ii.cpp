class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int deletions = 0;
        
        // Track which consecutive pairs are already sorted
        vector<bool> sorted(n - 1, false);
        
        // For each column
        for (int col = 0; col < m; col++) {
            bool canKeep = true;
            vector<bool> newSorted = sorted;
            
            // Check each consecutive pair
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i]) {
                    // This pair is not yet determined to be sorted
                    if (strs[i][col] < strs[i + 1][col]) {
                        // This column makes them sorted
                        newSorted[i] = true;
                    } else if (strs[i][col] > strs[i + 1][col]) {
                        // This column violates order - must delete
                        canKeep = false;
                        break;
                    }
                    // If equal, continue to next column for this pair
                }
            }
            
            if (canKeep) {
                sorted = newSorted;
            } else {
                deletions++;
            }
        }
        
        return deletions;
    }
};