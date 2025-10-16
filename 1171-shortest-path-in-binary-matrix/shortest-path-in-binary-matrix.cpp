class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0)
            return -1;
        if (n == 1)
            return 1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;
        int r = 0, c = 0;
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1},  {1, 0},  {1, 1}};
        queue<pair<int, pair<int, int>>> que;
        que.push({0, {0, 1}});
        while (!que.empty()) {
            auto r = que.front().first;
            auto c = que.front().second.first;
            auto dist = que.front().second.second;
            que.pop();

            if (r == n - 1 && c == m - 1)
                return dist;

            for (auto [dr, dc] : dirs) {
                int row = r + dr;
                int col = c + dc;
                if (row >= 0 && row < n && col >= 0 && col < m &&
                    !vis[row][col] && grid[row][col] == 0) {
                    vis[row][col] = 1;
                    que.push({row, {col, dist + 1}});
                }
            }
        }
        return -1;
    }
};