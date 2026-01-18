class Solution {
    bool isValid(vector<vector<int>>& g, int i, int j, int k) {
        int sum = 0;

        for (int x = i; x < i + k; x++) {
            int s = 0;
            for (int y = j; y < j + k; y++) s += g[x][y];
            if (x == i) sum = s;
            else if (sum != s) return false;
        }

        for (int y = j; y < j + k; y++) {
            int s = 0;
            for (int x = i; x < i + k; x++) s += g[x][y];
            if (sum != s) return false;
        }

        int s = 0;
        for (int d = 0; d < k; d++) s += g[i + d][j + d];
        if (sum != s) return false;

        s = 0;
        for (int d = 0; d < k; d++) s += g[i + d][j + k - 1 - d];
        if (sum != s) return false;

        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isValid(grid, i, j, k)) res = k;
                }
            }
        }
        return res;
    }
};