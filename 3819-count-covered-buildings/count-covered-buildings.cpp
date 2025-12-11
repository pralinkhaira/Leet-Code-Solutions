class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> rows;
        unordered_map<int, pair<int, int>> cols;
        
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (rows.find(x) == rows.end()) {
                rows[x] = {y, y};
            } else {
                rows[x].first = min(rows[x].first, y);
                rows[x].second = max(rows[x].second, y);
            }
            if (cols.find(y) == cols.end()) {
                cols[y] = {x, x};
            } else {
                cols[y].first = min(cols[y].first, x);
                cols[y].second = max(cols[y].second, x);
            }
        }
        
        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            bool hasLeftRight = (y > rows[x].first && y < rows[x].second);
            bool hasAboveBelow = (x > cols[y].first && x < cols[y].second);
            if (hasLeftRight && hasAboveBelow) {
                count++;
            }
        }
        return count;
    }
};