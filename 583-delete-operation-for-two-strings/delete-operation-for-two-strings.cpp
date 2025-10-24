class Solution {
public:
int n;
int m;
int t[501][501];
int solve(string &word1,string &word2,int i,int j){
    if(i>=n||j>=m) return max(n-i,m-j);
    
    
    if(t[i][j]!=-1) return t[i][j];


    if(word1[i]==word2[j]) return t[i][j]= solve(word1,word2,i+1,j+1);

    int x = 1+solve(word1,word2,i+1,j);
    int y= 1+solve(word1,word2,i,j+1);
    
    return t[i][j]=min(x,y);

}
    int minDistance(string word1, string word2) {
        n=word1.size();
        m=word2.size();

        memset(t,-1,sizeof(t));
        return solve(word1,word2,0,0);
    }
};