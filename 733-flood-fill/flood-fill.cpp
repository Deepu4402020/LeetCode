class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        vector<vector<int>> v(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        v[sr][sc] = 1;
        image[sr][sc] = color;  

        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& [dr, dc] : dir) {
                int new_r = r + dr;
                int new_c = c + dc;

                if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n &&
                    !v[new_r][new_c] && image[new_r][new_c] == originalColor) 
                {
                    q.push({new_r, new_c});
                    v[new_r][new_c] = 1;
                    image[new_r][new_c] = color;
                }
            }
        }

        return image;
    }
};