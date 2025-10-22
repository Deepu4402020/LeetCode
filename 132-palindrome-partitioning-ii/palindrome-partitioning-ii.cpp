class Solution {
public:
    int solve(string s) {
        int n = s.length();
        vector<int> t(n);
        vector<vector<bool>> P(n, vector<bool>(n, false));
        for(int i = 0; i<n; i++) {
            P[i][i] = true;
        }
        for(int l = 2; l<=n; l++) {
            for(int i = 0; i<n-l+1; i++) {
                int j = i+l-1;
                
                if(l == 2)
                    P[i][j] = (s[i] == s[j]);
                else {
                    P[i][j] = ((s[i] == s[j]) && P[i+1][j-1]);
                }
            }
        }

        //Best example to understand this - "abcb"
        for(int i = 0; i<n; i++) {
            if(P[0][i] == true)
                t[i] = 0;
            else {
                t[i] = i;//maximum possble cuts [0->i]
                for(int k = 0; k<i; k++) {//k->partition index
                    if(P[k+1][i] == true && 1 + t[k] < t[i])
                        t[i] = 1 + t[k];
                }   
            }
        }
        return t[n-1];
    }
    
    int minCut(string s) {
        int n = s.length();
        if(n == 0 || n == 1)
            return 0;
        
        return solve(s);
    }
};
