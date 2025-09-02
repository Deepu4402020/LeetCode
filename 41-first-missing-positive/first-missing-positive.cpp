class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }
        // overwriting array
        for (int i = 0; i < n; i++) {
            int val=abs(nums[i]);
            if (val <= n && val > 0) {//****
                if(nums[val-1]>0)
                  nums[val - 1] *= -1;


                else  if(nums[val-1]==0)
                nums[val-1]=-1*(n+1); 
    
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                return i+1;
            }
        }
        return n+1;
    }
};