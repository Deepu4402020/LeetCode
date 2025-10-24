class Solution {
public:
    bool solve(int i, int remSum, vector<int>& arr, vector<vector<int>>& t) {
        if ( remSum== 0) return true;
        if (i == 0) return remSum == arr[i];

        if (t[i][remSum] != -1)    return t[i][remSum];
        
        // skip
        bool x = solve(i - 1, remSum, arr, t);
       
        bool y = false;
         //should take
        if (remSum >= arr[i]) {
            y = solve(i - 1, remSum - arr[i], arr, t);
        }

        return t[i][remSum] = (x || y);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;
        if (sum % 2 == 1)  return false;
        
        int target = sum/ 2;
        vector<vector<int>> t(nums.size(), vector<int>(target + 1, -1));

        return solve(nums.size() - 1, target, nums, t);
    }
};