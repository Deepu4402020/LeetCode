class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v = grid;
        queue<pair<int, int>> q;
        int cfresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 2) {
                    q.push({i, j});
                }
                if (v[i][j] == 1) {
                    cfresh++;
                }
            }
        }
        if (cfresh == 0)
            return 0;
        if (q.empty())
            return -1;
        
        int t = -1;
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < m && j >= 0 && j < n && v[i][j] == 1) {
                        v[i][j] = 2;
                        cfresh--;
                        q.push({i, j});
                    }
                }
            }
            t++;
        }
        
        if (cfresh == 0)
            return t;
        return -1;
    }
};