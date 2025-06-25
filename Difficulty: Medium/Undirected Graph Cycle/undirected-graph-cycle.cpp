class Solution {
  public:
    bool checkcycle(int i, vector<int>& visited, vector<vector<int>>& adj) {
        visited[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true;  // Cycle detected
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (checkcycle(i, visited, adj)) {
                    return true;
                }
            }
        }

        return false;
    }
};