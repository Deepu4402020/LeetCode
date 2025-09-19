class Solution {
public:
    long long solve(int i, const vector<int>& nums, vector<vector<long long>>& memo, bool flag) {
        if (i >= nums.size())
            return 0;

        if (memo[i][flag] != -1)
            return memo[i][flag];

        long long val = flag ? nums[i] : -1LL * nums[i];

        long long take = solve(i + 1, nums, memo, !flag) + val;
        long long skip = solve(i + 1, nums, memo, flag);

        return memo[i][flag] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> memo(nums.size() + 1, vector<long long>(2, -1));
        return solve(0, nums, memo, true); // true -> +ve, false -> -ve
    }
};