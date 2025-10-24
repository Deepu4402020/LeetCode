class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));
        

        for (int i = 0; i <= n; i++)
            t[i][m] = n - i;
        for (int j = 0; j <= m; j++)
            t[n][j] = m - j;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (word1[i] == word2[j]) {
                    t[i][j] = t[i + 1][j + 1];
                } else {
                    t[i][j] = 1 + min(t[i + 1][j], t[i][j + 1]);
                }
            }
        }
        return t[0][0];
    }
};