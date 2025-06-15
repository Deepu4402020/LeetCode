class Solution {
public:
    void dfs(int node, vector<vector<int>> mat, vector<int>& vis) {
        vis[node] = 1;
        for (int i = 0; i < mat[node].size(); ++i) {
            if (mat[node][i] == 1 && !vis[i]) {
                dfs(i, mat, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, isConnected, vis);
                provinces++;
            }
        }

        return provinces;
    }
};