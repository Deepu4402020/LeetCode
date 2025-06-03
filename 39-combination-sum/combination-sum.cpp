class Solution {
public:
    void solve(vector<int> c,int t,int i,int sum,vector<int> subset,vector<vector<int>>&res){
        if(i==c.size()||sum>t) return;
        if(sum==t) {res.push_back(subset);return;}

        //Not taken
        solve(c,t,i+1,sum,subset,res);
       
       
       //taken
        subset.push_back(c[i]);
        solve(c,t,i,sum+c[i],subset,res);
        //issme sirf current index taken not taken hi h 
        
        subset.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;vector<int>subset;
        solve(candidates,target,0,0,subset,res);
        return res;
    }
};