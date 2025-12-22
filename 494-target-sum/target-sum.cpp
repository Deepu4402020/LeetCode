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

    int findTargetSumWays(vector<int>& nums, int t) {
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2001,0));
         
         //BASE CASE
          dp[n][t+1000]=1;

          //Recur simulaiton
        for (int i = n - 1; i >= 0; i--) {
            for (int cur_sum = -1000; cur_sum <= 1000; cur_sum++) {
                int idx = cur_sum + 1000;

                int plus = cur_sum + nums[i];
                int minus = cur_sum - nums[i];

                if (plus >= -1000 && plus <= 1000)
                    dp[i][idx] += dp[i + 1][plus + 1000];

                if (minus >= -1000 && minus <= 1000)
                    dp[i][idx] += dp[i + 1][minus + 1000];
            }
        }
        return dp[0][1000];

    }
};