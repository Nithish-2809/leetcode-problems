class Solution {
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev = 1;
        int preprev = 1;
        int curr;

        for(int i=2;i<=n;i++) {
            curr = prev+preprev;
            preprev = prev;
            prev = curr;
        }

    return prev;
    }
};