class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> ans;
        set<int> set(nums.begin(), nums.end());
        auto it=set.rbegin();
        for(int i=0; i<k; i++){
            if(it!=set.rend()){
            ans.push_back(*it);
            it++;
            }
        }
        return ans;
    }
};