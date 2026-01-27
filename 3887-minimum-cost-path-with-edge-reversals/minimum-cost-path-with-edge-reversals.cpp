class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const int INF = INT_MAX / 2;

        // Adjacency list: graph[u] = {v, cost}
        vector<vector<pair<int,int>>> graph(n);

        // Add asymmetric edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w * 2});
        }

        // Distance array
        vector<int> dist(n, INF);
        dist[0] = 0;

        // Min-heap for Dijkstra: {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &edge : graph[node]) {
                int next = edge.first;
                int cost = edge.second;

                if (dist[next] > d + cost) {
                    dist[next] = d + cost;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist[n - 1] >= INF ? -1 : dist[n - 1];
    }
};
