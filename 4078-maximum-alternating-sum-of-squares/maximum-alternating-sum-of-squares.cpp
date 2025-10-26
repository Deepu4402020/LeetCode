class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
       for(int i=0;i<n;i++){
        nums[i]=abs(nums[i]);
       }
       sort(nums.begin(),nums.end());
       long long sum=0;
       for(int i=0;i<n/2;i++){
     //   cout<<i <<" ";
        sum-=(long long)nums[i]*nums[i];
       }
        for(int i=(n/2);i<n;i++){
           // cout<<i<<" ";
        sum+=(long long)nums[i]*nums[i];
       }
       return sum;

    }
};