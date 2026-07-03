int countContribution(int row, int col, const vector<vector<int>>& grid) {
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();

    // Top
    if (row == 0 || grid[row - 1][col] == 0)
        cnt++;

    // Bottom
    if (row == n - 1 || grid[row + 1][col] == 0)
        cnt++;

    // Left
    if (col == 0 || grid[row][col - 1] == 0)
        cnt++;

    // Right
    if (col == m - 1 || grid[row][col + 1] == 0)
        cnt++;

    return cnt;
}





void calculatePerimeter(const vector<vector<int>>& grid, vector<vector<int>>&visited,int i,int j,int &perimeter) {
    queue<pair<int,int>>q;
    int n = grid.size();
    int m = grid[0].size();

    q.push({i,j});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        perimeter += countContribution(row,col,grid);

        if(row<n-1 && !visited[row+1][col] && grid[row+1][col]==1) {
            q.push({row+1,col});
            visited[row+1][col] = 1;
        }

        //up
        if(row>0 && !visited[row-1][col] && grid[row-1][col]==1) {
            q.push({row-1,col});
            visited[row-1][col] = 1;
        }

        //right
        if(col<m-1 && !visited[row][col+1] && grid[row][col+1]==1) {
            q.push({row,col+1});
            visited[row][col+1] = 1;
        }

        //left
        if(col>0 && !visited[row][col-1] && grid[row][col-1]==1) {
            q.push({row,col-1});
            visited[row][col-1] = 1;
        }
    }
}



class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j]==1) {
                    visited[i][j] = 1;
                    calculatePerimeter(grid,visited,i,j,perimeter);
                    break;
                }
            }
        }

    return perimeter;
    }
};