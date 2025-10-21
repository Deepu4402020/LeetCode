class Solution {
public:
int t[501][501];
//from index i->j tak kitne insertion kiye.

    int minInsertions(string s) {
        int n=s.size();
        memset(t,0,sizeof(t));

        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
               
                if(s[i]==s[j]){
                    t[i][j]=t[i+1][j-1];
                }
                else{
                    t[i][j]=1+min(t[i+1][j],t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};