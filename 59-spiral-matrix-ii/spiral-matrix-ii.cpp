class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,1));
        //index intialisation
        int strow=0, stcol=0;
        int endrow=n-1,endcol=n-1;
        //counters
        int cnt=n*n;
        int a=1;
        
        while(a<=cnt){
            
            //enter value in starting row
            for(int i=stcol;i<=endcol&&a<=cnt;i++){
                ans[strow][i]=a;
                a++;
            }
            strow++;
            
            //enter value in ending col
            for(int i=strow;i<=endrow&&a<=cnt;i++){
                ans[i][endcol]=a;
                a++;
            }
            endcol--;
            
            //enter value in ending row
            for(int i=endcol;i>=stcol&&a<=cnt;i--){
                ans[endrow][i]=a;
                a++;
            }
            endrow--;
            
            //enter value in starting col
            for(int i=endrow;i>=strow&&a<=cnt;i--){
                ans[i][stcol]=a;
                a++;
            }
            stcol++;
        }
        return ans;
    }
};