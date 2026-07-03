class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int,int>,int>>q;

        vector<vector<int>>visited(n,vector<int>(n,0));

        if(grid[0][0]==1) return -1;
        q.push({{0,0},1});
        visited[0][0] = 1;


        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int len = q.front().second;
            q.pop();

            if(row==n-1 && col==n-1) return len;

            //down
            if(row<n-1 && !visited[row+1][col] && grid[row+1][col]==0) {
                visited[row+1][col] = 1;
                q.push({{row+1,col},len+1});
            }

            //up
            if(row>0 && !visited[row-1][col] && grid[row-1][col]==0) {
                visited[row-1][col] = 1;
                q.push({{row-1,col},len+1});
            }

            //right
            if(col<n-1 && !visited[row][col+1] && grid[row][col+1]==0) {
                visited[row][col+1] = 1;
                q.push({{row,col+1},len+1});
            }

            //left
            if(col>0 && !visited[row][col-1] && grid[row][col-1]==0) {
                visited[row][col-1] = 1;
                q.push({{row,col-1},len+1});
            }

            //right-up
            if(row>0 && col<n-1 && !visited[row-1][col+1] && grid[row-1][col+1]==0) {
                visited[row-1][col+1] = 1;
                q.push({{row-1,col+1},len+1});
            }

            //right-down
            if(row<n-1 && col<n-1 && !visited[row+1][col+1] && grid[row+1][col+1]==0) {
                visited[row+1][col+1] = 1;
                q.push({{row+1,col+1},len+1});
            }

            //left-up
            if(row>0 && col>0 && !visited[row-1][col-1] && grid[row-1][col-1]==0) {
                visited[row-1][col-1] = 1;
                q.push({{row-1,col-1},len+1});
            }

            //left-down
            if(row<n-1 && col>0 && !visited[row+1][col-1] && grid[row+1][col-1]==0) {
                visited[row+1][col-1] = 1;
                q.push({{row+1,col-1},len+1});
            }
        }

    return -1;
    }
};