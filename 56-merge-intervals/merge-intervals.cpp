class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        
        while(i<intervals.size()){
            int start= intervals[i][0];
            int end= intervals[i][1];
            while(i<intervals.size()-1&&end>=intervals[i+1][0]){
                end= max(intervals[i+1][1],end);
                i++;
            }
            result.push_back({start,end});
            i++;
        }
        return result;
    }
};