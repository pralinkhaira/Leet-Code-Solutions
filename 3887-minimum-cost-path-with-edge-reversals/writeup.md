![Meme](https://github.com/user-attachments/assets/571a52a4-9567-421e-b2ad-dd6aea843edb)
## 🚀 Ultra-Fast Dijkstra with Asymmetric Edge Costs

**Runtime:** `205 ms`
**Performance:** **Beats 91.11%** of submissions 🏎️

---

## 🧠 Intuition

The problem can be modeled as a weighted graph where each edge behaves **asymmetrically**. Traveling from `u → v` has cost `w`, while traveling back from `v → u` costs `2w`. Since all edge weights are positive, the shortest path from node `0` to node `n-1` can be efficiently computed using **Dijkstra’s algorithm**.

To maximize performance, the focus is on minimizing overhead inside the algorithm while preserving correctness.

---

## 🛠️ Approach

1. **Graph Construction**
   Build an adjacency list where each edge is added twice:

   * Forward edge with cost `w`
   * Reverse edge with cost `2w` (implemented using a bit shift for speed)

2. **Optimized Dijkstra**

   * Use a **min-heap (priority queue)** storing `{distance, node}`
   * Maintain a distance array initialized to infinity
   * Skip outdated heap states using `d != dist[node]`
   * **Early exit** as soon as the destination node is popped from the heap, since Dijkstra guarantees optimality at that moment

3. **Low-level Optimizations**

   * Custom `struct` instead of `pair` for better cache locality
   * `emplace` / lightweight objects in the priority queue
   * Bit shifting (`w << 1`) instead of multiplication

These optimizations together push the solution into the top performance bracket.

---

## ⏱️ Complexity

* **Time Complexity:**
  (O((V + E) \log V)) using Dijkstra’s algorithm with a binary heap

* **Space Complexity:**
  (O(V + E)) for the adjacency list, distance array, and priority queue

---

## 💻 Code

```cpp
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
            graph[v].push_back({u, w << 1});
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
```

---

✨ **Result:** A clean, highly optimized Dijkstra solution that comfortably achieves **91%+ performance**, striking a strong balance between readability and speed.
