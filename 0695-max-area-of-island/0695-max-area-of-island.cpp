class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        int maxSize = 0;
       

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    q.push({i,j});
                    visited[i][j] = true;
                     int size = 1;
                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        //down
                        if(row<n-1 && !visited[row+1][col] && grid[row+1][col]==1) {
                            size++;
                            visited[row+1][col] = true;
                            q.push({row+1,col});
                        }

                        //up
                        if(row>0 && !visited[row-1][col] && grid[row-1][col]==1) {
                            size++;
                            visited[row-1][col] = true;
                            q.push({row-1,col});
                        }

                        //right
                        if(col<m-1 && !visited[row][col+1] && grid[row][col+1]==1) {
                            size++;
                            visited[row][col+1] = true;
                            q.push({row,col+1});
                        }

                        //left
                        if(col>0 && !visited[row][col-1] && grid[row][col-1]==1) {
                            size++;
                            visited[row][col-1] = true;
                            q.push({row,col-1});
                        }

                        maxSize = max(maxSize,size);
                    }
                }
            }
        }
    return maxSize;
    }
};