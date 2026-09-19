int maximumProfit(const vector<int>& prices, int index, int transactions,
                  bool buy, vector<vector<vector<int>>>& dp) {
    int n = prices.size();
    if (index > n - 1 || transactions == 2) {
        return 0;
    }
    if (dp[index][transactions][buy] !=-1)
        return dp[index][transactions][buy];
    int profit = 0;
    if (buy) {
        int take = -prices[index] +
                   maximumProfit(prices, index + 1, transactions, false,dp);
        int notTake = maximumProfit(prices, index + 1, transactions, true,dp);

        return dp[index][transactions][buy] = max(take, notTake);
    }

    int sell = prices[index] +
               maximumProfit(prices, index + 1, transactions + 1, true,dp);
    int notSell = maximumProfit(prices, index + 1, transactions, false,dp);
    return dp[index][transactions][buy] = max(sell, notSell);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(3, vector<int>(2, -1)));

        return maximumProfit(prices, 0, 0, true, dp);
    }
};