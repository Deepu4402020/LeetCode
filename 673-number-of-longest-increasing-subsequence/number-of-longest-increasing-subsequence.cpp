class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { // can increase our seq.
                    if (t[j] + 1 == t[i]) {
                        count[i] += count[j];
                    } else if (t[j] + 1 > t[i]) {
                        t[i] = t[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }
        int max_val=*max_element(t.begin(),t.end());
        int res=0;
        for(auto i=0;i<n;i++){
            if(t[i]==max_val) res+=count[i];
        }
        return res;
    }
};