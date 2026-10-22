bool isReachable(const vector<vector<int>>& grid, int health,
                 int row, int col, vector<vector<int>>& visited,
                 vector<vector<vector<int>>>&dp) {
    int n = grid.size();
    int m = grid[0].size();


    if (grid[row][col] == 1) {
        health--;
    }

    if (health <= 0) {
        return false;
    }

    if (row == n - 1 && col == m - 1) {
        return true;
    }

    if(dp[health][row][col]!=-1) return dp[health][row][col];

    visited[row][col] = 1;

    bool goLeft = false;
    bool goRight = false;
    bool goUp = false;
    bool goDown = false;

    if (row + 1 < n && !visited[row + 1][col]) {
        goDown = isReachable(grid, health, row + 1, col, visited,dp);
    }

    if (row - 1 >= 0 && !visited[row - 1][col]) {
        goUp = isReachable(grid, health, row - 1, col, visited,dp);
    }

    if (col + 1 < m && !visited[row][col + 1]) {
        goRight = isReachable(grid, health, row, col + 1, visited,dp);
    }

    if (col - 1 >= 0 && !visited[row][col - 1]) {
        goLeft = isReachable(grid, health, row, col - 1, visited,dp);
    }

    visited[row][col] = 0;

    return dp[health][row][col] = goLeft || goRight || goDown || goUp;
}

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<vector<vector<int>>>dp(health+1,vector<vector<int>>(
            n,vector<int>(m,-1)
        ));


        return isReachable(grid, health, 0, 0, visited,dp);
    }
};