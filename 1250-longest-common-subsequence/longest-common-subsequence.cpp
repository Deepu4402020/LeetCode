class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        //t[i][j] = LCS length of s1[0...i-1] and s2[0...j-1]
        
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                } else if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        return t[m][n];
    }
};