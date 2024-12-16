class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int brpnt = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                brpnt = i;
                break;
            }
        }
        if (brpnt == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int j = n - 1; j > brpnt; --j) {
            if (nums[j] > nums[brpnt]) {
                swap(nums[j], nums[brpnt]);
                break;
            }
        }
        reverse(nums.begin() + brpnt + 1, nums.end());
    }
};