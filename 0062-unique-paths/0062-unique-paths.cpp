int calculateNumberOfPaths(int row,int col,const vector<vector<int>>&grid,vector<vector<int>>&dp) {
    int n = grid.size();
    int m = grid[0].size();

    if(row==n-1 && col==m-1) return 1;

    if(dp[row][col]!=-1) return dp[row][col];

    int goBottom = 0;
    if(row+1<n) {
        goBottom = calculateNumberOfPaths(row+1,col,grid,dp);
    }
    int goRight = 0;
    if(col+1<m) {
        goRight = calculateNumberOfPaths(row,col+1,grid,dp);
    }

    return dp[row][col] = goBottom+goRight;
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return calculateNumberOfPaths(0,0,grid,dp);
    }
};