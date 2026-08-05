int maximumProfit(vector<int>& prices, int index, bool canBuy, int transactionsLeft,vector<vector<vector<int>>>&dp) {
    int n = prices.size();

    if (index == n || transactionsLeft == 0)
        return 0;

    if(dp[index][canBuy][transactionsLeft]!=-1) return dp[index][canBuy][transactionsLeft];

    if (canBuy) {
        return dp[index][canBuy][transactionsLeft] = max(
            -prices[index] + maximumProfit(prices, index + 1, false, transactionsLeft,dp), // buy
            maximumProfit(prices, index + 1, true, transactionsLeft,dp)                    // skip
        );
    }
    else {
        return dp[index][canBuy][transactionsLeft] = max(
            prices[index] + maximumProfit(prices, index + 1, true, transactionsLeft - 1,dp), // sell
            maximumProfit(prices, index + 1, false, transactionsLeft,dp)                      // hold
        );
    }
}



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(2, vector<int>(3, -1))
        );

        return maximumProfit(prices,0,true,2,dp);
    }
};