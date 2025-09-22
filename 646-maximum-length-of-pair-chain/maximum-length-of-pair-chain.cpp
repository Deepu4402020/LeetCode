class Solution {
public:

//Rec+Memo
    int solve(int i, vector<vector<int>>& pairs, vector<vector<int>>& memo, int prevSel_idx) {
        if (i >= pairs.size()) return 0;

        int prev = (prevSel_idx == -1 ? pairs.size() : prevSel_idx);

        if (memo[i][prev] != -1) return memo[i][prev];

        // Select
        int take = (prevSel_idx == -1 || pairs[prevSel_idx][1] < pairs[i][0])
                   ? 1 + solve(i+1, pairs, memo, i) : solve(i+1, pairs, memo, prevSel_idx);

        // Skip
        int skip = solve(i+1, pairs, memo, prevSel_idx);

        return memo[i][prev] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());  

        int n = pairs.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return solve(0, pairs, memo, -1);
    }
};