int fibonocci(int n,vector<int>&dp) {
    if(n<=1) {
        return n;
    }
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fibonocci(n-1,dp)+fibonocci(n-2,dp);
}





class Solution {
public:
    int fib(int n) {
        vector<int>dp(n+1,-1);

        return fibonocci(n,dp);
    }
};