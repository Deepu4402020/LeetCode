class Solution {
public:
    int solve(vector<int>& nums,vector<int>&t){
        int maxlen=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<=i;j++){
                if(nums[i]>nums[j]){
                    t[i]=max(t[j]+1,t[i]);
                    maxlen=max(maxlen,t[i]);
                }
            }
        }
        return maxlen;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> t(nums.size(),1); // smallest size would be 1 as himslef as sebsequence
        return solve(nums,t);
    }
};