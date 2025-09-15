class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        int presum = 0;
        for (int i = 0; i < n; i++) {
            int rightSum = sum - presum - nums[i];
            if (presum == rightSum) {
                return i;
            }
            presum += nums[i];
        }
        
        return -1;
    }
};