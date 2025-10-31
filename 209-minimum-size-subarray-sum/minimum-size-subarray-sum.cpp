class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0;
        int res = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];  

            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
};