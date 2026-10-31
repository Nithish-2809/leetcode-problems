class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int row, int col, int cameFrom) {
        int n = grid.size();
        int m = grid[0].size();

        if(row >= n || col >= m) return 0;

        if(row == n-1 && col == m-1) return 1;

        if(dp[row][col][cameFrom] != -1)
            return dp[row][col][cameFrom];

        // Current cell is a mirror
        if(grid[row][col] == 1) {
            if(cameFrom == 0) {
                return dp[row][col][cameFrom] =
                    solve(grid, row+1, col, 1);
            }
            else {
                return dp[row][col][cameFrom] =
                    solve(grid, row, col+1, 0);
            }
        }

        int goDown = solve(grid, row+1, col, 1);
        int goRight = solve(grid, row, col+1, 0);

        return dp[row][col][cameFrom] =
            (goDown + goRight) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(2, -1)));

        // Starting cell has no previous direction.
        // Handle it separately by trying both directions.
        if(grid[0][0] == 1) return 0;

        int goDown = solve(grid, 1, 0, 1);
        int goRight = solve(grid, 0, 1, 0);

        return (goDown + goRight) % MOD;
    }
};