class Solution {
  public:
    bool checkcycle(int i, vector<int>& v, vector<vector<int>>& adj) {
        v[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neig : adj[node]) {
                if (!v[neig]) {
                    v[neig] = 1;
                    q.push({neig, node});
                } else if (neig != parent) {
                    return true;  
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

        vector<int> v(V, 0);

        for (int i = 0; i < V; ++i) {
            if (!v[i]) {
                if (checkcycle(i, v, adj)) {
                    return true;
                }
            }
        }

        return false;
    }
};
