class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int n=a.size();
        int ans=a[0];
        for(int i=1;i<n;i++){
            ans+=max(a[i]-a[i-1],0);
        }
        return ans;
    }
};