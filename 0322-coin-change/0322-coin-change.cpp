class Solution {
public:
    const int INF = 1e9;

    int solve(vector<int>& coins, int index, int amount,vector<vector<int>>&dp) {
        int n = coins.size();

        if (amount == 0)
            return 0;

        if (index == n)
            return INF;

        if(dp[index][amount]!=-1) return dp[index][amount];

        // Don't take current coin
        int notTake = solve(coins, index + 1, amount,dp);

        // Take current coin (stay at same index)
        int take = INF;
        if (coins[index] <= amount) {
            take = 1 + solve(coins, index, amount - coins[index],dp);
        }

        return dp[index][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(coins, 0, amount,dp);
       

        return (ans >= INF) ? -1 : ans;
    }
};