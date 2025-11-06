#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        // Step 1: Union all connected stations
        for (auto& conn : connections) {
            int a = conn[0], b = conn[1];
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[rb] = ra;
        }

        // Step 2: Build linked order within each component
        vector<int> next_node(c + 1, 0), comp_min(c + 1, 0), last(c + 1, 0);
        for (int i = 1; i <= c; ++i) {
            int r = find(i);
            if (comp_min[r] == 0) {
                comp_min[r] = i;
            } else {
                next_node[last[r]] = i;
            }
            last[r] = i;
        }

        vector<bool> offline(c + 1, false);
        vector<int> res;

        // Step 3: Process queries
        for (auto& q : queries) {
            int t = q[0], x = q[1];

            if (t == 1) { // Maintenance check
                if (!offline[x]) {
                    res.push_back(x);
                } else {
                    int r = find(x);
                    res.push_back(comp_min[r] ? comp_min[r] : -1);
                }
            } 
            else { // Station goes offline
                if (!offline[x]) {
                    offline[x] = true;
                    int r = find(x);
                    if (comp_min[r] == x) {
                        int y = next_node[x];
                        while (y && offline[y]) y = next_node[y];
                        comp_min[r] = y ? y : 0;
                    }
                }
            }
        }

        return res;
    }
};