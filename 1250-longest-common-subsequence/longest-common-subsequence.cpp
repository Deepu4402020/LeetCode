class Solution {
public:
    int memo[1001][1001];
    int m, n;

    int solve(string& s, string& t) {
        // Initialize first row and column to 0
        for (int i = 0; i <= m; i++) memo[i][0] = 0;
        for (int j = 0; j <= n; j++) memo[0][j] = 0;

       // i ,j are length so index would be i-1,j-1
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    memo[i][j] = 1 + memo[i - 1][j - 1]; // take match
                } else {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]); // skip
                }
            }
        }

        return memo[m][n]; 
    }

    int longestCommonSubsequence(string s, string t) {
        m = s.size();
        n = t.size();
        return solve(s, t);
    }
};