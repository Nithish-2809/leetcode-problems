int solve(int step,int n,vector<int>&dp) {
    if(step==n) return 1;
    if(step>n) return 0;
    if(dp[step]!=-1) return dp[step];

    return dp[step] = solve(step+1,n,dp)+solve(step+2,n,dp);
}


class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(0,n,dp);
    }
};