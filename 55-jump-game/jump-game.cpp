class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJ = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxJ) return false;
            maxJ = max(maxJ, i + nums[i]);
        }
        return true;
    }
};