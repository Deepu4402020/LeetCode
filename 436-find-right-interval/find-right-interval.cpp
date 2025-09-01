class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>ans;
        
        vector<pair<int,int>> start;//{start,index}
        for(int i=0;i<n;i++){
        start.push_back({intervals[i][0],i});
        }
        sort(start.begin(),start.end());
        for(int i=0;i<n;i++){
            int ending = intervals[i][1];
           for(auto it:start){
              auto e=start.rbegin();
                if(it.first>=ending){
                    ans.push_back(it.second);
                    break;
                }
                else if(it.first == e->first){
                    ans.push_back(-1);
                }
           } 
        }

        return ans;
    }
};