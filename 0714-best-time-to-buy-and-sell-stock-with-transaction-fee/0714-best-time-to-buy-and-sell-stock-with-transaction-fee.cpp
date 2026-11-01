
int maximumProfit(vector<int>& prices, int fee, int index, bool buy,
                  vector<vector<int>>& dp) {
    int n = prices.size();

    if(index == n) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    if(buy) {
        return dp[index][buy] = max(
            -prices[index] + maximumProfit(prices, fee, index+1, false, dp),
            maximumProfit(prices, fee, index+1, true, dp)
        );
    }

    return dp[index][buy] = max(
        prices[index] - fee + maximumProfit(prices, fee, index+1, true, dp),
        maximumProfit(prices, fee, index+1, false, dp)
    );
}

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return maximumProfit(prices, fee, 0, true, dp);
    }
};
