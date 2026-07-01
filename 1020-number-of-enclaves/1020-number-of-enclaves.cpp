class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int unsafeCells = 0;
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || i==n-1 || j==0 || j==m-1) {
                    if(grid[i][j]==1) {
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }


        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //down
            if(row<n-1 && visited[row+1][col]==0 && grid[row+1][col]==1) {
                q.push({row+1,col});
                visited[row+1][col] = 1;
            }

            //up
            if(row>0 && visited[row-1][col]==0 && grid[row-1][col]==1) {
                q.push({row-1,col});
                visited[row-1][col] = 1;
            }

            //right
            if(col<m-1 && visited[row][col+1]==0 && grid[row][col+1]==1) {
                q.push({row,col+1});
                visited[row][col+1] = 1;
            }

            //left
            if(col>0 && visited[row][col-1]==0 && grid[row][col-1]==1) {
                q.push({row,col-1});
                visited[row][col-1] = 1;
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    unsafeCells++;
                }
            }
        }
        
    return unsafeCells;
    }
};