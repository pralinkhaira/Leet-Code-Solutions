class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(m, INF));
        cost[n - 1][m - 1] = 0;

        vector<pair<int, int>> cells;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cells.push_back({i, j});

        sort(cells.begin(), cells.end(),
             [&](const pair<int, int>& a, const pair<int, int>& b) {
                 return grid[a.first][a.second] <
                        grid[b.first][b.second];
             });

        for (int step = 0; step <= k; step++) {

            if (step > 0) {
                int best = INF;
                int idx = 0;
                while (idx < (int)cells.size()) {
                    int v = grid[cells[idx].first][cells[idx].second];
                    int j = idx;

                    while (j < (int)cells.size() &&
                           grid[cells[j].first][cells[j].second] == v) {
                        best = min(best,
                                   cost[cells[j].first][cells[j].second]);
                        j++;
                    }

                    for (int t = idx; t < j; t++) {
                        cost[cells[t].first][cells[t].second] = best;
                    }

                    idx = j;
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i + 1 < n)
                        cost[i][j] = min(cost[i][j],
                                         cost[i + 1][j] + grid[i + 1][j]);
                    if (j + 1 < m)
                        cost[i][j] = min(cost[i][j],
                                         cost[i][j + 1] + grid[i][j + 1]);
                }
            }
        }

        return cost[0][0];
    }
};
