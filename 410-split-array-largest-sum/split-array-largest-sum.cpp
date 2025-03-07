class Solution {
public:

    int ifPossible(vector<int>& nums, int mid)
    {
        int curr = 1;
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(sum+nums[i]<=mid)
            {
                sum += nums[i];

            }
            else
            {
                curr++;
                sum=nums[i];
            }
        }
        return curr;
    }

    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);

        while(s<=e)
        {
            int mid = s + (e-s) /2;

            int ans = ifPossible(nums,mid);

            if(ans<=k)
            {
                e=mid-1;
            }
            else
            {
               s=mid+1;
            }
        }
        return s;
    }
};