int countUniquePaths(const vector<vector<int>>&obstacleGrid,int row,int col,vector<vector<int>>&dp) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    if(row>=n || col>=m) return 0;
    
    if(row==n-1 && col==m-1 ) {
        return (obstacleGrid[row][col]==0);
    }

    if(obstacleGrid[row][col]==1) return 0;

    if(dp[row][col]!=-1) return dp[row][col];

    int goDown = 0;

    if(row+1<n) {
        goDown = countUniquePaths(obstacleGrid,row+1,col,dp);
    }

    int goRight = 0;

    if(col+1<m) {
        goRight = countUniquePaths(obstacleGrid,row,col+1,dp);
    }

    return dp[row][col] = goDown+goRight;
}


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return countUniquePaths(obstacleGrid,0,0,dp);
    }
};