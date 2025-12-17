class Solution {
private:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& prices, int i, int buy) {
        if (i == n) return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if (buy == 0) {

            int take = -prices[i] + solve(prices, i + 1, 1);

            int skip = solve(prices, i + 1, 0);
            profit = max(take, skip);
        } else {

            int sell = prices[i] + solve(prices, i + 1, 0);

            int hold = solve(prices, i + 1, 1);
            profit = max(sell, hold);
        }

        return dp[i][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(prices, 0, 0);
    }
};