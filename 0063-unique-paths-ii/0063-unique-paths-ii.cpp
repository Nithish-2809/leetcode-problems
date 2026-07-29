int countUniquePaths(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    if(row==n-1 && col==m-1 && obstacleGrid[row][col]!=1) return 1;
    if(row>n-1 || col>m-1) return 0;

    if(dp[row][col]!=-1) return dp[row][col];

    int uniquePaths = 0;

    if(obstacleGrid[row][col]!=1 && row+1<n && obstacleGrid[row+1][col]!=1) {
        uniquePaths += countUniquePaths(row+1,col,obstacleGrid,dp);
    }

    if(obstacleGrid[row][col]!=1 && col+1<m  && obstacleGrid[row][col+1]!=1) {
        uniquePaths += countUniquePaths(row,col+1,obstacleGrid,dp);
    }

    return dp[row][col] = uniquePaths;
}



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
       return countUniquePaths(0,0,obstacleGrid,dp);
    }
};