class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;

        for(int &i:nums){
            mp[i]++;
            if(mp[i]>1) ans.push_back(i);
        }
        return ans;
    }
};