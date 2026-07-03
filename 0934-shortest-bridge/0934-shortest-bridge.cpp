class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        bool found = false;

        
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    found = true;
                    break;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1 &&
                    !visited[nr][nc]) {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        
        queue<pair<pair<int, int>, int>> qu;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) {
                    qu.push({{i, j}, 0});
                }
            }
        }

        while (!qu.empty()) {
            int row = qu.front().first.first;
            int col = qu.front().first.second;
            int dist = qu.front().second;
            qu.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if (visited[nr][nc])
                    continue;

                if (grid[nr][nc] == 1)
                    return dist;

                visited[nr][nc] = true;
                qu.push({{nr, nc}, dist + 1});
            }
        }

        return -1;
    }
};