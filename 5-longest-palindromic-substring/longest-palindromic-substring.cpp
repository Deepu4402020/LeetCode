class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n));
        int maxL = 0;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            t[i][i] = true;
            maxL = 1;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    idx = i;
                }
                else if (s[i] == s[j] && t[i + 1][j - 1] == true) {
                    t[i][j] = true;
                    if (j - i + 1 > maxL) {
                        maxL = j - i + 1;
                        idx = i;
                    }
                }
                else {
                    t[i][j] = false; 
                }
            }
        }

        return s.substr(idx, maxL);
    }
};