class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]!=0 && !visited[i][j]) {
                    q.push({i,j});
                    visited[i][j] = 1;
                    long long sum = grid[i][j];

                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        if(row+1<n && grid[row+1][col]!=0 && !visited[row+1][col]) {
                            visited[row+1][col] = 1;
                            sum += grid[row+1][col];
                            q.push({row+1,col});
                        }

                        if(row-1>=0 && grid[row-1][col]!=0 && !visited[row-1][col]) {
                            visited[row-1][col] = 1;
                            sum += grid[row-1][col];
                            q.push({row-1,col});
                        }

                        if(col+1<m && grid[row][col+1]!=0 && !visited[row][col+1]) {
                            visited[row][col+1] = 1;
                            sum += grid[row][col+1];
                            q.push({row,col+1});
                        }

                        if(col-1>=0 && grid[row][col-1]!=0 && !visited[row][col-1]) {
                            visited[row][col-1] = 1;
                            sum += grid[row][col-1];
                            q.push({row,col-1});
                        }
                    }

                    if(sum%k==0) islands++;  
                }
            }
        }

    return islands;
    }
};