class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return 0;

        vector<vector<int>> arr(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            if (grid[i][0]) break;
            arr[i][0] = 1;
        }

        for (int j = 0; j < m; j++) { 
            if (grid[0][j]) break;
            arr[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j]) { // Obstracle
                    arr[i][j] = 0;
                }
                else {
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
                }
            }
        }
        return arr[n - 1][m - 1];
    }
};