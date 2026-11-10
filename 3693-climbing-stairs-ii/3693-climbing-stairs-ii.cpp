class Solution {
public:
    vector<int>dp;
    int helper(int n, vector<int>& costs, int i){
        if (i==n) return 0;
        if (dp[i]!= -1) return dp[i];
        int cost= costs[i]+ 1+ helper(n, costs, i+1);
        if (i+2<=n) cost= min(cost, costs[i+1]+ 4+ helper(n, costs, i+2));
        if (i+3<=n) cost= min(cost, costs[i+2]+ 9+ helper(n, costs, i+3));
        return dp[i]=cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp=vector<int>(n+1, -1);
        return helper(n, costs, 0);
    }
};