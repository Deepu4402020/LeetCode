class Solution {
public:
    int subarraySum(std::vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for (int i = 0; i < n; i++) {
            int start = std::max(0, i - nums[i]);
            for (int j = start; j <= i; j++) {
                total_sum += nums[j];
            }
        }
        
        return total_sum;
    }
};