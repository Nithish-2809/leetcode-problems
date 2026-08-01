class Solution {
public:
    int solve(int row, int col1, int col2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return -1e9;

        // Last row
        if (row == n - 1) {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int cherries = 0;
        if (col1 == col2)
            cherries = grid[row][col1];
        else
            cherries = grid[row][col1] + grid[row][col2];

        int maxi = -1e9;

        // Try all 9 possible moves
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                maxi = max(maxi,
                           solve(row + 1, col1 + d1, col2 + d2, grid, dp));
            }
        }

        return dp[row][col1][col2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m - 1, grid, dp);
    }
};