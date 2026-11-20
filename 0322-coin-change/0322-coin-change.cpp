int numberOfCoins(vector<int>& coins, int amount, int index,vector<vector<int>>&dp) {

    if(amount == 0) return 0;

    if(amount < 0 || index == coins.size())
        return INT_MAX;

    if(dp[index][amount]!=-1) return dp[index][amount];

    int notTake = numberOfCoins(coins, amount, index + 1,dp);

    int take = INT_MAX;

    if(coins[index] <= amount) {
        int res = numberOfCoins(coins, amount - coins[index], index,dp);

        if(res != INT_MAX)
            take = 1 + res;
    }

    return dp[index][amount] = min(notTake, take);
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans = numberOfCoins(coins, amount, 0,dp);

        return ans == INT_MAX ? -1 : ans;
    }
};