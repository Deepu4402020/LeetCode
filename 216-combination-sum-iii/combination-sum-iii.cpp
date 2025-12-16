class Solution {
public:
void solve(vector<vector<int>>& ans,int rem ,int i,int can_select,vector<int> &cur_comb){
if(can_select==0&&rem==0){ans.push_back(cur_comb); return;}
if(can_select<0||rem<0||i>9) return;

//skip
solve(ans,rem,i+1,can_select,cur_comb);
//select
cur_comb.push_back(i);
solve(ans,rem-i,i+1,can_select-1,cur_comb);
cur_comb.pop_back();

return;
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>cur_comb;
         solve(ans,n,1,k,cur_comb);
         return ans;
    }
};