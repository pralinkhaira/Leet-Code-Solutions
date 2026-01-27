class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const int INF = INT_MAX / 2;

        vector<vector<pair<int,int>>> graph(n);
        for (const auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w * 2);
        }

        vector<int> dist(n, INF);
        dist[0] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // Skip outdated state
            if (d != dist[node]) continue;

            // Early exit: shortest path to destination found
            if (node == n - 1) return d;

            for (const auto &edge : graph[node]) {
                int next = edge.first;
                int cost = edge.second;

                int newDist = d + cost;
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    pq.emplace(newDist, next);
                }
            }
        }

        return -1;
    }
};
