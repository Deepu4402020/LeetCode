class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        // code

        for(int i=0;i<nums.size();i++){
            int diff= target -nums[i];

            if(hash.find(diff)!=hash.end()){
              return{i,hash[diff]};
            }
            hash[nums[i]]=i;
        }
        
          return{};

    }
};