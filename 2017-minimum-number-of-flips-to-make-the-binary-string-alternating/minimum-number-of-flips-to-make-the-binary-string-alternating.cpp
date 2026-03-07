class Solution {
public:
    int minFlips(auto& s) {
        int n = s.length();
        int op[2] = {0, 0};

        for (int i = 0; i < n; i++)
            op[(s[i] ^ i) & 1]++;

        int res = min(op[0], op[1]);

        for (int i = 0; i < n - 1; i++) {
            op[(s[i] ^ i) & 1]--;
            op[(s[i] ^ (n + i)) & 1]++;
            res = min(res, min(op[0], op[1]));
        }

        return res;
    }
};