class Solution {
public:
    struct Edge {
        int to, cost;
    };

    struct Node {
        int d, v;
        bool operator>(const Node& o) const {
            return d > o.d;
        }
    };

    int minCost(int n, vector<vector<int>>& edges) {
        const int INF = INT_MAX / 2;

        vector<vector<Edge>> g(n), rg(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w << 1});

            // reverse graph
            rg[v].push_back({u, w});
            rg[u].push_back({v, w << 1});
        }

        vector<int> distF(n, INF), distB(n, INF);
        priority_queue<Node, vector<Node>, greater<Node>> pqF, pqB;

        distF[0] = 0;
        distB[n - 1] = 0;

        pqF.push({0, 0});
        pqB.push({0, n - 1});

        int ans = INF;

        while (!pqF.empty() || !pqB.empty()) {
            if (!pqF.empty()) {
                auto [d, u] = pqF.top(); pqF.pop();
                if (d != distF[u]) continue;
                if (d >= ans) break;

                for (auto &e : g[u]) {
                    int nd = d + e.cost;
                    if (nd < distF[e.to]) {
                        distF[e.to] = nd;
                        pqF.push({nd, e.to});
                        if (distB[e.to] < INF)
                            ans = min(ans, nd + distB[e.to]);
                    }
                }
            }

            if (!pqB.empty()) {
                auto [d, u] = pqB.top(); pqB.pop();
                if (d != distB[u]) continue;
                if (d >= ans) break;

                for (auto &e : rg[u]) {
                    int nd = d + e.cost;
                    if (nd < distB[e.to]) {
                        distB[e.to] = nd;
                        pqB.push({nd, e.to});
                        if (distF[e.to] < INF)
                            ans = min(ans, nd + distF[e.to]);
                    }
                }
            }
        }

        return ans == INF ? -1 : ans;
    }
};
