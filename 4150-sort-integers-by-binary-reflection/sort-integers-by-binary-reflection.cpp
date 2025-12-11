class Solution {
public:
    static bool cmp(int a, int b){
        int p1 = a, p2 = b;
        int s1 = 0, s2 = 0;
        while(p1){
            int l = (p1&1);
            if(l == 1) s1 = ((s1 << 1) | 1);
            else s1 = (s1 << 1);         
            p1 = (p1 >> 1);
        }
        while(p2){
            int l = (p2&1);
            if(l == 1) s2 = ((s2 << 1) | 1);
            else s2 = (s2 << 1);            
            p2 = (p2 >> 1);
        }
        if(s1 == s2) return a < b;
        return s1 < s2;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};