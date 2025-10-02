class Solution {
public:
    int binary_Search(int l, int r, int target, vector<int>& nums,
                      bool findFirst) {
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                (findFirst) ? r = mid - 1 : l = mid + 1; // keep searching right

            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int fidx = binary_Search(0, nums.size() - 1, target, nums, true);
        int lidx = binary_Search(0, nums.size() - 1, target, nums, false);
        return {fidx, lidx};
    }
};