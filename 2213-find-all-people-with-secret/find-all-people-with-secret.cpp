class Solution {
private:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px != py) {
            parent[px] = py;
        }
    }
    
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // Unite person 0 and firstPerson
        unite(0, firstPerson);
        
        // Sort meetings by time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        int i = 0;
        while (i < meetings.size()) {
            int currentTime = meetings[i][2];
            set<int> peopleAtTime;
            map<int, set<int>> graph;
            
            // Build graph of meetings at this time
            while (i < meetings.size() && meetings[i][2] == currentTime) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                graph[x].insert(y);
                graph[y].insert(x);
                peopleAtTime.insert(x);
                peopleAtTime.insert(y);
                i++;
            }
            
            // For each connected component in the graph, check if anyone knows the secret
            set<int> visited;
            for (int start : peopleAtTime) {
                if (visited.count(start)) continue;
                
                // BFS to find connected component
                vector<int> component;
                queue<int> q;
                q.push(start);
                visited.insert(start);
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    component.push_back(u);
                    
                    for (int v : graph[u]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                    }
                }
                
                // Check if any person in component knows secret
                bool anyKnows = false;
                for (int person : component) {
                    if (find(person) == find(0)) {
                        anyKnows = true;
                        break;
                    }
                }
                
                // If yes, unite all in component
                if (anyKnows) {
                    for (int j = 1; j < component.size(); j++) {
                        unite(component[0], component[j]);
                    }
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
