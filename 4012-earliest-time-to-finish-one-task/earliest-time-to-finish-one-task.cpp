class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini=INT_MAX;
        for(auto i:tasks){
             mini=min(i[0]+i[1],mini);
        }
        return mini;

    }
};