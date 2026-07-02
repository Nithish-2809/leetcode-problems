class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        health -= grid[0][0];
        if (health <= 0) return false;

        if (n == 1 && m == 1) return true;

        vector<vector<int>> best(n, vector<int>(m, -1));
        queue<pair<pair<int,int>,int>> q;

        q.push({{0, 0}, health});
        best[0][0] = health;

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currHealth = q.front().second;
            q.pop();

            // Down
            if (row < n - 1) {
                int newHealth = currHealth - grid[row + 1][col];

                if (newHealth > 0 && newHealth > best[row + 1][col]) {
                    if (row + 1 == n - 1 && col == m - 1)
                        return true;

                    best[row + 1][col] = newHealth;
                    q.push({{row + 1, col}, newHealth});
                }
            }

            // Up
            if (row > 0) {
                int newHealth = currHealth - grid[row - 1][col];

                if (newHealth > 0 && newHealth > best[row - 1][col]) {
                    best[row - 1][col] = newHealth;
                    q.push({{row - 1, col}, newHealth});
                }
            }

            // Right
            if (col < m - 1) {
                int newHealth = currHealth - grid[row][col + 1];

                if (newHealth > 0 && newHealth > best[row][col + 1]) {
                    if (row == n - 1 && col + 1 == m - 1)
                        return true;

                    best[row][col + 1] = newHealth;
                    q.push({{row, col + 1}, newHealth});
                }
            }

            // Left
            if (col > 0) {
                int newHealth = currHealth - grid[row][col - 1];

                if (newHealth > 0 && newHealth > best[row][col - 1]) {
                    best[row][col - 1] = newHealth;
                    q.push({{row, col - 1}, newHealth});
                }
            }
        }

        return false;
    }
};