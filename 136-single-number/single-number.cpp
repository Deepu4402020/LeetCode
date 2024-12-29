class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int numb = 0;
        for(int i = 0; i < nums.size(); i++){
            numb ^= nums[i];
        }
        return numb;
    }
};
