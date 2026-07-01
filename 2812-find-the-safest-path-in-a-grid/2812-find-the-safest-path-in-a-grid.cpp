class Solution {
public:
    bool isSafeFactor(vector<vector<int>>& safeFactor, int n, int mid) {
        if (safeFactor[0][0] < mid || safeFactor[n - 1][n - 1] < mid)
            return false;

        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            if (row == n - 1 && col == n - 1)
                return true;

            // Up
            if (row - 1 >= 0 && !visited[row - 1][col] &&
                safeFactor[row - 1][col] >= mid) {
                visited[row - 1][col] = 1;
                q.push({row - 1, col});
            }

            // Down
            if (row + 1 < n && !visited[row + 1][col] &&
                safeFactor[row + 1][col] >= mid) {
                visited[row + 1][col] = 1;
                q.push({row + 1, col});
            }

            // Left
            if (col - 1 >= 0 && !visited[row][col - 1] &&
                safeFactor[row][col - 1] >= mid) {
                visited[row][col - 1] = 1;
                q.push({row, col - 1});
            }

            // Right
            if (col + 1 < n && !visited[row][col + 1] &&
                safeFactor[row][col + 1] >= mid) {
                visited[row][col + 1] = 1;
                q.push({row, col + 1});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> safeFactor(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Push all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    safeFactor[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            // Up
            if (row - 1 >= 0 && safeFactor[row - 1][col] == INT_MAX) {
                safeFactor[row - 1][col] = safeFactor[row][col] + 1;
                q.push({row - 1, col});
            }

            // Down
            if (row + 1 < n && safeFactor[row + 1][col] == INT_MAX) {
                safeFactor[row + 1][col] = safeFactor[row][col] + 1;
                q.push({row + 1, col});
            }

            // Left
            if (col - 1 >= 0 && safeFactor[row][col - 1] == INT_MAX) {
                safeFactor[row][col - 1] = safeFactor[row][col] + 1;
                q.push({row, col - 1});
            }

            // Right
            if (col + 1 < n && safeFactor[row][col + 1] == INT_MAX) {
                safeFactor[row][col + 1] = safeFactor[row][col] + 1;
                q.push({row, col + 1});
            }
        }

        int low = 0;
        int high = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = max(high, safeFactor[i][j]);
            }
        }

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isSafeFactor(safeFactor, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};