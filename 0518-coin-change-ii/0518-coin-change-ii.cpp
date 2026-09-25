int solve(const vector<int>&coins,int amount,int index,vector<vector<int>>&dp) {
    int n = coins.size();
    if(amount==0) return 1;

    if(index==n) {
        return (amount==0);
    }

    if(dp[index][amount]!=-1) return dp[index][amount];

    int take = 0;

    if(amount-coins[index]>=0) {
        take = solve(coins,amount-coins[index],index,dp);
    }
    int notTake = solve(coins,amount,index+1,dp);

    return dp[index][amount] = take+notTake;
}


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};