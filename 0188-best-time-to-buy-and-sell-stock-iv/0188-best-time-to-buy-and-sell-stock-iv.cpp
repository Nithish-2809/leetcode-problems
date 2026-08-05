class Solution {
public:
    int solve(vector<int>& prices, int index, bool canBuy,
              int transactionsLeft,
              vector<vector<vector<int>>>& dp) {

        int n = prices.size();

        if (index == n || transactionsLeft == 0)
            return 0;

        if (dp[index][canBuy][transactionsLeft] != -1)
            return dp[index][canBuy][transactionsLeft];

        int profit;

        if (canBuy) {
            profit = max(
                -prices[index] + solve(prices, index + 1, false,
                                       transactionsLeft, dp),
                solve(prices, index + 1, true,
                      transactionsLeft, dp)
            );
        }
        else {
            profit = max(
                prices[index] + solve(prices, index + 1, true,
                                      transactionsLeft - 1, dp),
                solve(prices, index + 1, false,
                      transactionsLeft, dp)
            );
        }

        return dp[index][canBuy][transactionsLeft] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return solve(prices, 0, true, k, dp);
    }
};