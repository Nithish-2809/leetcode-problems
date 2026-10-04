bool countSubislands(int i, int j,
                     const vector<vector<int>>& grid1,
                     const vector<vector<int>>& grid2,
                     vector<vector<int>>& visited) {
    
    queue<pair<int,int>> q;
    int n = grid1.size();
    int m = grid1[0].size();

    q.push({i, j});
    visited[i][j] = 1;

    bool result = true;

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(grid1[row][col] != 1) {
            result = false;
        }

        // down
        if(row + 1 < n && grid2[row + 1][col] == 1 && !visited[row + 1][col]) {
            q.push({row + 1, col});
            visited[row + 1][col] = 1;
        }

        // up
        if(row - 1 >= 0 && grid2[row - 1][col] == 1 && !visited[row - 1][col]) {
            q.push({row - 1, col});
            visited[row - 1][col] = 1;
        }

        // right
        if(col + 1 < m && grid2[row][col + 1] == 1 && !visited[row][col + 1]) {
            q.push({row, col + 1});
            visited[row][col + 1] = 1;
        }

        // left
        if(col - 1 >= 0 && grid2[row][col - 1] == 1 && !visited[row][col - 1]) {
            q.push({row, col - 1});
            visited[row][col - 1] = 1;
        }
    }

    return result;
}

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        int subIslands = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1 && !visited[i][j]) {
                    if(countSubislands(i, j, grid1, grid2, visited)) {
                        subIslands++;
                    }
                }
            }
        }

        return subIslands;
    }
};