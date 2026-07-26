class Solution {
public:
    int findMinCost(vector<int>& cost, int index, int n,vector<int>&dp) {
        // Reached the top
        if (index >= n)
            return 0;
        
        if(dp[index]!=-1) return dp[index];

        int oneStep = findMinCost(cost, index + 1, n,dp);
        int twoStep = findMinCost(cost, index + 2, n,dp);

        return dp[index] = cost[index] + min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);

        return min(findMinCost(cost, 0, n,dp),
                   findMinCost(cost, 1, n,dp));
    }
};