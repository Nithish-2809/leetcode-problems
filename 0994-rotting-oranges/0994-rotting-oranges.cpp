class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //{time,{row,column}}
        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({0,{i,j}});
                }
            }
        }

        int timeTaken = 0;

        while(!q.empty()) {
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            timeTaken = max(timeTaken,time);

            //DOWN
            if(row+1<n && grid[row+1][col]==1) {
                grid[row+1][col] = 2;
                q.push({time+1,{row+1,col}});
            }

            //UP
            if(row-1>=0 && grid[row-1][col]==1) {
                grid[row-1][col] = 2;
                q.push({time+1,{row-1,col}});
            }

            //RIGHT
            if(col+1<m && grid[row][col+1]==1) {
                grid[row][col+1] = 2;
                q.push({time+1,{row,col+1}});
            }

            //LEFT
            if(col-1>=0 && grid[row][col-1]==1) {
                grid[row][col-1] = 2;
                q.push({time+1,{row,col-1}});
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) return -1;
            }
        }

    return timeTaken;
    }
};