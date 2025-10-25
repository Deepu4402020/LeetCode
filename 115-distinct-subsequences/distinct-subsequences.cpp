class Solution {
public:
    int memo[1001][1001];
    int solve(int i, int j,string& s, string& t) {
        if (j == t.size()) return 1; 
        if (i == s.size()) return 0; 

        if(memo[i][j]!=-1) return memo[i][j];
        // take
        int x=0;
        if(s[i]==t[j])
          x += solve(i + 1, j+1,s, t);
        // skip
         x+= solve(i + 1,j, s, t);

        return  memo[i][j]=x ;
    }
    int numDistinct(string s, string t) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0,s, t);
    }
};