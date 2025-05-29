class Solution {
public:
void solve (vector<int> nums,int idx,vector<int>&subset,vector<vector<int>>&res){
if(idx==nums.size()) { 
   // if(find(res.begin(),res.end(),subset)==res.end()){
        res.push_back(subset); 
      //  }
return;}

 //Don't Add
  solve(nums,idx+1, subset, res);


   //Add
   subset.push_back(nums[idx]);
    solve(nums,idx+1,subset,res);//backtrack
    subset.pop_back();

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        solve(nums, 0,subset,res);
        return res;
    }
};