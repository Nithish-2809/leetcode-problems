class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        int noOfIslands = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    q.push({i,j});
                    visited[i][j] = 1;
                    noOfIslands++;
                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        //down
                        if(row<n-1 && !visited[row+1][col] && grid[row+1][col]=='1') {
                            visited[row+1][col] = 1;
                            q.push({row+1,col});
                        }

                        //up
                        if(row>0 && !visited[row-1][col] && grid[row-1][col]=='1') {
                            visited[row-1][col] = 1;
                            q.push({row-1,col});
                        }

                        //right
                        if(col<m-1 && !visited[row][col+1] && grid[row][col+1]=='1') {
                            visited[row][col+1] = 1;
                            q.push({row,col+1});
                        }

                        //left
                        if(col>0 && !visited[row][col-1] && grid[row][col-1]=='1') {
                            visited[row][col-1] = 1;
                            q.push({row,col-1});
                        }

                    }
                }
            }
        }
    return noOfIslands;
    }
};