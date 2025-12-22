class Solution {
public:
    int n;
    int solve(vector<int>& nums, int t, int i, int cur_sum,vector<vector<int>>&dp) {
        if (i == n) {
            return cur_sum == t ? 1 : 0;
        }
        int idx=cur_sum+1000;
        if(dp[i][idx]!=-1){
            return dp[i][idx];
        }
        int ans = 0;
        //+
        ans += solve(nums, t, i + 1, cur_sum + nums[i],dp);
        //-
        ans += solve(nums, t, i + 1, cur_sum - nums[i],dp);

        return dp[i][idx]=ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return solve(nums, target, 0, 0,dp);
    }
};