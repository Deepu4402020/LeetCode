class Solution {
public:
    int dp(vector<int>& nums, int i, int ans, int lastidx, vector<int>& memo) {
        if (i > lastidx) return ans;
        if (memo[i] != -1) return ans + memo[i];

        int take = dp(nums, i + 2, ans + nums[i], lastidx, memo);

        int skip = dp(nums, i + 1, ans, lastidx, memo);

        memo[i] = max(take, skip) - ans;
        return max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> memo1(n, -1), memo2(n, -1);

        return max(dp(nums, 0, 0, n - 2, memo1), dp(nums, 1, 0, n - 1, memo2));
    }
};