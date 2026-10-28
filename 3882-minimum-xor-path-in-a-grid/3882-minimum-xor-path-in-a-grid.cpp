class Solution {
public:
    int calculateMinXORPath(vector<vector<int>>& grid, int row, int col,
                            int xorValue, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        xorValue ^= grid[row][col];

        if (row == n - 1 && col == m - 1) {
            return xorValue;
        }

        if (dp[row][col][xorValue] != -1) {
            return dp[row][col][xorValue];
        }

        int goRight = INT_MAX;
        int goDown = INT_MAX;

        if (col + 1 < m) {
            goRight = calculateMinXORPath(
                grid, row, col + 1, xorValue, dp
            );
        }

        if (row + 1 < n) {
            goDown = calculateMinXORPath(
                grid, row + 1, col, xorValue, dp
            );
        }

        return dp[row][col][xorValue] = min(goRight, goDown);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Assumption: every grid value is in [0, 1023].
        int maxXOR = 1024;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(
                m, vector<int>(maxXOR, -1)
            )
        );

        return calculateMinXORPath(grid, 0, 0, 0, dp);
    }
};