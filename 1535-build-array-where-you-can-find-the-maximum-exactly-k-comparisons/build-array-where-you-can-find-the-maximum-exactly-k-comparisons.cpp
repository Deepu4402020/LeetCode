class Solution {
public:
    int MOD = 1e9+7;
    int t[51][51][101]; // dp[len][ccost][maxSel]

    int rec(int n, int m, int k, int len, int ccost, int maxSel) {
        // Base case
        if (len == n) {
            return (ccost == k);
        }

        if (t[len][ccost][maxSel] != -1) {
            return t[len][ccost][maxSel];
        }

        long long cnt = 0;
        for (int val = 1; val <= m; val++) {
            if (val > maxSel) {
                if (ccost + 1 <= k) 
                    cnt += rec(n, m, k, len+1, ccost+1, val);
            } else {
                cnt += rec(n, m, k, len+1, ccost, maxSel);
            }
            if (cnt >= MOD) cnt -= MOD;
        }
        return t[len][ccost][maxSel] = cnt % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        memset(t, -1, sizeof(t));
        return rec(n, m, k, 0, 0, 0); 
    }
};