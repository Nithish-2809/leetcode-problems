int solve(int i,int j,vector<int>nums,vector<vector<int>>&dp) {
    if(i==j) {
        return nums[i];
    }


    if(j<i) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int pick_i = nums[i] + min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
    int pick_j = nums[j] + min(solve(i,j-2,nums,dp),solve(i+1,j-1,nums,dp));

    return dp[i][j] = max(pick_i,pick_j);
}


class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        int player1Points = solve(0,n-1,nums,dp);
        int player2Points = sum-player1Points;

        if(player1Points>=player2Points) return true;

    return false;
    }
};