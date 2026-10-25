
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int closedIslands = 0;

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 0 && !visited[i][j]) {

                    q.push({i, j});
                    visited[i][j] = 1;

                    bool isClosed = true;

                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        if(row == 0 || row == n-1 ||
                           col == 0 || col == m-1) {
                            isClosed = false;
                        }

                        if(row+1 < n && grid[row+1][col] == 0 &&
                           !visited[row+1][col]) {
                            q.push({row+1, col});
                            visited[row+1][col] = 1;
                        }

                        if(col+1 < m && grid[row][col+1] == 0 &&
                           !visited[row][col+1]) {
                            q.push({row, col+1});
                            visited[row][col+1] = 1;
                        }

                        if(row-1 >= 0 && grid[row-1][col] == 0 &&
                           !visited[row-1][col]) {
                            q.push({row-1, col});
                            visited[row-1][col] = 1;
                        }

                        if(col-1 >= 0 && grid[row][col-1] == 0 &&
                           !visited[row][col-1]) {
                            q.push({row, col-1});
                            visited[row][col-1] = 1;
                        }
                    }

                    if(isClosed) {
                        closedIslands++;
                    }
                }
            }
        }

        return closedIslands;
    }
};
