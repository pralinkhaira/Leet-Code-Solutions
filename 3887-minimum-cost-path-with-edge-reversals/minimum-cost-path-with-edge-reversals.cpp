class Solution {
public:
    struct Edge {
        int to;
        int cost;
    };

    struct Node {
        int dist;
        int v;
        bool operator>(const Node& other) const {
            return dist > other.dist;
        }
    };

    int minCost(int n, vector<vector<int>>& edges) {
        const int INF = INT_MAX / 2;

        vector<vector<Edge>> graph(n);
        graph.reserve(n);

        for (const auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w << 1});  // w * 2 (bit shift faster)
        }

        vector<int> dist(n, INF);
        dist[0] = 0;

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            int d = cur.dist;
            int u = cur.v;

            if (d != dist[u]) continue;
            if (u == n - 1) return d;

            for (const Edge &e : graph[u]) {
                int nd = d + e.cost;
                if (nd < dist[e.to]) {
                    dist[e.to] = nd;
                    pq.push({nd, e.to});
                }
            }
        }

        return -1;
    }
};
