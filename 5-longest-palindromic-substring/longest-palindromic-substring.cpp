class Solution {
public:
    int t[1001][1001];

    bool solve(string& s, int i, int j) {

        if (i >= j) return true;  

        if (t[i][j] != -1) return t[i][j]; 

        if (s[i] != s[j]) return t[i][j] = false;

        return t[i][j] = solve(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {
        memset(t, -1, sizeof(t));
        int n = s.size();

        int start = 0;
        int maxLen = 1; 

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};