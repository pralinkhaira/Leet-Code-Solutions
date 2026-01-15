class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        auto maxSpan = [](vector<int>& bars) {
            int res = 1, streak = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] - bars[i - 1] == 1) streak++;
                else streak = 1;
                res = max(res, streak);
            }
            return ++res;
        };

        int s = min(maxSpan(hBars), maxSpan(vBars));
        return s * s;
    }
};
