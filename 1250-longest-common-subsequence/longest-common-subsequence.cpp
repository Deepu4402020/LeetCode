class Solution {
public:
    int memo[1001][1001];

    int solve(string &s, string &t, int si, int ti) {
        if (si >= s.size() || ti >= t.size()) {
            return 0;
        }

        if (memo[si][ti] != -1) {
            return memo[si][ti];
        }

        // can take
        if (s[si] == t[ti]) {
            return memo[si][ti] = 1 + solve(s, t, si + 1, ti + 1);
        }

        // skip 1st char
        int x = solve(s, t, si + 1, ti);
        int y = solve(s, t, si, ti + 1);

        return memo[si][ti] = max(x, y);
    }

    int longestCommonSubsequence(string s, string t) {
        memset(memo, -1, sizeof(memo));  
        return solve(s, t, 0, 0);
    }
};