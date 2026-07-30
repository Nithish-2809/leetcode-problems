int countMinimumPathsum(vector<vector<int>>&grid,int row,int col,int n,int m,vector<vector<int>>&dp) {
    if(row==n-1 && col==m-1) {
        return grid[row][col];
    }

    if(dp[row][col]!=-1) return dp[row][col];

    int down = INT_MAX;
    int right= INT_MAX;
    
    if(row+1<n) {
        down = grid[row][col] + countMinimumPathsum(grid,row+1,col,n,m,dp);
    }

    if(col+1<m) {
        right = grid[row][col] + countMinimumPathsum(grid,row,col+1,n,m,dp);
    }
    
    return dp[row][col] = min(down,right);
}



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return countMinimumPathsum(grid,0,0,n,m,dp);
    }
};