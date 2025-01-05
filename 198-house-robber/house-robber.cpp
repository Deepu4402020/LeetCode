class Solution {
public:
    int rob(vector<int>& nums) {
        const int len = nums.size();
        //vector<int> table(nums);
        int a = 0;
        int b = 0;
        int c;
        for(int i = 0; i < len; i++) {
            c = max( nums[i] + a, b);
            a = b;
            b = c;
        }
        return c;
    }
};