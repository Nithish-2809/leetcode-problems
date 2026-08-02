int solve(vector<int>&piles,int i,int j,vector<vector<int>>&dp) {
    if(i==j) {
        return piles[i];
    }
    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int leftPick = piles[i]+min(solve(piles,i+2,j,dp),solve(piles,i+1,j-1,dp));
    int rightPick = piles[j]+min(solve(piles,i+1,j-1,dp),solve(piles,i,j-2,dp));

    return dp[i][j] = max(leftPick,rightPick);
}


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += piles[i];
        }

        int aliceScore = solve(piles,0,n-1,dp);

        int bobScore = sum - aliceScore;

        return aliceScore>bobScore;
    }
};