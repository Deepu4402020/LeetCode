class Solution {
public:
    // Recursion + Memoization
    int solve(vector<int>& nums, int i, int prev_idx, vector<vector<int>>& memo) {
        int n = nums.size();
        if (i >= n) return 0;

        if (memo[i][prev_idx + 1] != -1) 
            return memo[i][prev_idx + 1];

        int taken = 0;
        if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
            taken = 1 + solve(nums, i + 1, i, memo);
        }
        int skip = solve(nums, i + 1, prev_idx, memo);

        return memo[i][prev_idx + 1] = max(skip, taken);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return solve(nums, 0, -1, memo);
    }
};