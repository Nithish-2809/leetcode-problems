class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int maxArea = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j]==1) {
                    visited[i][j] = 1;
                    q.push({i,j});
                    int area = 1;

                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        if(row+1<n && grid[row+1][col]==1 && !visited[row+1][col]) {
                            area++;
                            visited[row+1][col] = 1;
                            q.push({row+1,col});
                        }

                        if(row-1>=0 && grid[row-1][col]==1 && !visited[row-1][col]) {
                            area++;
                            visited[row-1][col] = 1;
                            q.push({row-1,col});
                        }

                        if(col+1<m && grid[row][col+1]==1 && !visited[row][col+1]) {
                            area++;
                            visited[row][col+1] = 1;
                            q.push({row,col+1});
                        }

                        if(col-1>=0 && grid[row][col-1]==1 && !visited[row][col-1]) {
                            area++;
                            visited[row][col-1] = 1;
                            q.push({row,col-1});
                        }
                    }

                    maxArea = max(maxArea,area);
                }
            }
        }

    return maxArea;
    }
};