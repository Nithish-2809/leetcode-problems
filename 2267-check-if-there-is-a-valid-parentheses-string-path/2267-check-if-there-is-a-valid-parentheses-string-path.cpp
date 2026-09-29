bool ifPossible(vector<vector<char>>& grid, int row, int col, int balance,vector<vector<vector<int>>>&dp) {
    int n = grid.size();
    int m = grid[0].size();


    if(grid[row][col] == '(') balance++;
    else balance--;

  
    if(balance < 0) return false;

    if(row == n - 1 && col == m - 1) {
        return (balance == 0);
    }

      if(dp[row][col][balance]!=-1) return dp[row][col][balance];


    bool down = false;
    bool right = false;

    if(row + 1 < n) {
        down = ifPossible(grid, row + 1, col, balance,dp);
    }

    if(col + 1 < m) {
        right = ifPossible(grid, row, col + 1, balance,dp);
    }

    return dp[row][col][balance] = down || right;
}

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
    n,
    vector<vector<int>>(m, vector<int>(n + m, -1))
);

        if(grid[0][0] != '(' || grid[n - 1][m - 1] != ')') {
            return false;
        }


        return ifPossible(grid, 0, 0, 0,dp);
    }
};