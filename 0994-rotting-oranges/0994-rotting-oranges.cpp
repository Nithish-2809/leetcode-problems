class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Push all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else if (grid[i][j] == 1) {
                    visited[i][j] = 1;
                }
            }
        }

        int t = 0;

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            t = q.front().second;
            q.pop();

            // Down
            if (row + 1 < n && grid[row + 1][col] == 1 && visited[row + 1][col] == 1) {
                visited[row + 1][col] = 2;
                q.push({{row + 1, col}, t + 1});
            }

            // Up
            if (row - 1 >= 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == 1) {
                visited[row - 1][col] = 2;
                q.push({{row - 1, col}, t + 1});
            }

            // Right
            if (col + 1 < m && grid[row][col + 1] == 1 && visited[row][col + 1] == 1) {
                visited[row][col + 1] = 2;
                q.push({{row, col + 1}, t + 1});
            }

            // Left
            if (col - 1 >= 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == 1) {
                visited[row][col - 1] = 2;
                q.push({{row, col - 1}, t + 1});
            }
        }

        // Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 1)
                    return -1;
            }
        }

        return t;
    }
};