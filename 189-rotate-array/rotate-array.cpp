class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), j = n-k%n;
       reverse(nums.begin(),nums.begin()+j);
       reverse(nums.begin()+j,nums.end());
       reverse(nums.begin(),nums.end());
    }
};