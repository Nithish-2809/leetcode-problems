class Solution {
public:
    int getSum(vector<int>& pref, int l, int r) {
        return pref[r + 1] - pref[l];
    }

    int solve(vector<int>& pref, int l, int r,vector<vector<int>>&dp) {
        if (l == r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {
            int leftSum = getSum(pref, l, k);
            int rightSum = getSum(pref, k + 1, r);

            if (leftSum < rightSum) {
                ans = max(ans, leftSum + solve(pref, l, k,dp));
            }
            else if (leftSum > rightSum) {
                ans = max(ans, rightSum + solve(pref, k + 1, r,dp));
            }
            else {
                ans = max(ans,
                          leftSum +
                          max(solve(pref, l, k,dp),
                              solve(pref, k + 1, r,dp)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return solve(pref, 0, n - 1,dp);
    }
};