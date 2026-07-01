class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
               if(i==0 || j==0 || i==n-1 || j==m-1) {
                if(board[i][j]=='O') {
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
            if(row<n-1 && !visited[row+1][col]) {
                if( board[row+1][col]=='O') {
                    visited[row+1][col] = 1;
                    q.push({row+1,col});
                }
                else {
                    visited[row+1][col] = 2;
                }
            }

            //up
            if(row>0 && !visited[row-1][col]) {
                if( board[row-1][col]=='O') {
                    visited[row-1][col] = 1;
                    q.push({row-1,col});
                }
                else {
                    visited[row-1][col] = 2;
                }
            }

            //right

            if(col<m-1 && !visited[row][col+1]) {
                if( board[row][col+1]=='O') {
                    visited[row][col+1] = 1;
                    q.push({row,col+1});
                }
                else {
                    visited[row][col+1] = 2;
                }
            }

            //left
            if(col>0 && !visited[row][col-1]) {
                if( board[row][col-1]=='O') {
                    visited[row][col-1] = 1;
                    q.push({row,col-1});
                }
                else {
                    visited[row][col-1] = 2;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(visited[i][j]==1) {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};