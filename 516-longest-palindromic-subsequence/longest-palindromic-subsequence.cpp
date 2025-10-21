class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> t(n+1,vector<int>(n+1,0));
        //State t[i][j]-> i s j idx tak max subsequence
        for(int i=0;i<n;i++){
            t[i][i]=1;
        }
        for(int l=2;l<=n;l++){//length
            for(int i=0;i+l-1<n;i++){ //starting point
            int e=i+l-1;
                if(s[i]==s[e]){
                    t[i][e]=2+t[i+1][e-1];
                }
                else{
                    t[i][e]=max(t[i+1][e],t[i][e-1]);
                }
            }
        }
        return t[0][n-1];
    }
};