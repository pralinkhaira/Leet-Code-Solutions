class Solution {
public:
int countPermutations(vector<int>& complexity) {
        const int MOD = 1000000007;
        
        // Check if complexity[0] is the unique minimum
        int first = complexity[0];
        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= first) {
                return 0;
            }
        }
        
        // Calculate (n-1)! modulo MOD
        long long result = 1;
        for (int i = 2; i < complexity.size(); i++) {
            result = (result * i) % MOD;
        }
        
        return (int)result;        
    }
};