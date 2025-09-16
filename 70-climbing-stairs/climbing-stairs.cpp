class Solution {
public:
    int memo(int n, unordered_map<int, int>& mpp) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (mpp.find(n) == mpp.end()) {
            mpp[n] = memo(n-1, mpp) + memo(n-2, mpp);
        }
        return mpp[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> mpp;
        return memo(n, mpp);
    }
};