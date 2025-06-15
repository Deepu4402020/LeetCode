class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0; i < n;i++){
            if(nums[i] == 0) res[i] = 0;
            else if(nums[i] > 0){
                int idx = (i + nums[i]) % n;
                res[i] = nums[idx];
            }
            else{
                int idx = (i + n + (nums[i] % n)) % n;
                res[i] = nums[idx];
            }
        }
        return res;
    }
};