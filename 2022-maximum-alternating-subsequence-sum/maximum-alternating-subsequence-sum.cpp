class Solution {
public:
    // BOTTOM UP APPROACH
    //int dp[n+1][2];
    long long solve(vector<int>& nums) {
      int n=nums.size();
             vector<vector<long long>> dp(n, vector<long long>(2, 0));//0-> will be at even ,1-> elemnt would come at odd
      
      dp[0][0]=nums[0];
      dp[0][1]=0;
      for(int i=1;i<n;i++){
        //taken
        dp[i][0]=max(dp[i-1][1]+nums[i],dp[i-1][0]);

        dp[i][1]=max(dp[i-1][0]-nums[i],dp[i-1][1]);
      }
      return max(dp[n-1][0],dp[n-1][1]);
    } 
    long long maxAlternatingSum(vector<int>& nums) {
        return solve(nums);
    }
};