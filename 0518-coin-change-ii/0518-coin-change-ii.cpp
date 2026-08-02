int solve(int index,vector<int>&coins,int amount,vector<vector<int>>&dp) {
    int n = coins.size();
    if(index==n) {
        return (amount==0);
    }

    if(dp[index][amount]!=-1) return dp[index][amount];

    int notTake = solve(index+1,coins,amount,dp);
    int take = 0;
    if(coins[index]<=amount) {
        take = solve(index,coins,amount-coins[index],dp);
    }

    return dp[index][amount] = take+notTake;
}


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(0,coins,amount,dp);
    }
};