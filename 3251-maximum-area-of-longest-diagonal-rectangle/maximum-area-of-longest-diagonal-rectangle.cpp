class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& v) {
        int n=v.size();
        int ans=0;
        double d=0;
        for(int i=0;i<n;i++) {
            double t=sqrt(v[i][0]*v[i][0]+v[i][1]*v[i][1]);
            if(t>=d) {
                if(t==d)
                    ans=max(ans,v[i][0]*v[i][1]);
                else
                    ans=v[i][0]*v[i][1];
                d=t;
            }
        }
        return ans;
    }
};