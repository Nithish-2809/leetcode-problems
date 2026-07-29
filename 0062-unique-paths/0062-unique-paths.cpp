int numberOfPaths(int row,int col,int m,int n,vector<vector<int>>&dp) {
    if(row==m-1 && col==n-1) return 1;
    
    int numberOfUniquePaths = 0;

    if(dp[row][col]!=-1) return dp[row][col];

    if(col+1<n) {
       numberOfUniquePaths += numberOfPaths(row,col+1,m,n,dp);
    }

    if(row+1<m) {
       numberOfUniquePaths+= numberOfPaths(row+1,col,m,n,dp);
    }

    return dp[row][col] = numberOfUniquePaths;
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return numberOfPaths(0,0,m,n,dp);
    }
};