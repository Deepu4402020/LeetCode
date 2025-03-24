class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*max_element(nums.begin(),nums.end());
        int currMax=1,currMin=1;
        for(int n:nums){
            int temp =currMax*n;
            currMax=max({temp,currMin*n,n});
            currMin=min({temp,currMin*n,n});

            res=max(res,currMax);
        }
        return res;
    }
};