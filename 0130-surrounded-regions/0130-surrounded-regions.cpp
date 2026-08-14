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
                        visited[i][j] =1;
                    }
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //down
            if(row+1<n && board[row+1][col]=='O' && !visited[row+1][col]) {
                visited[row+1][col] = 1;
                q.push({row+1,col});
            }
            //up
            if(row-1>=0 && board[row-1][col]=='O' && !visited[row-1][col]) {
                visited[row-1][col] = 1;
                q.push({row-1,col});
            }
            //right
            if(col+1<m && board[row][col+1]=='O' && !visited[row][col+1]) {
                visited[row][col+1] = 1;
                q.push({row,col+1});
            }
            //left
            if(col-1>=0 && board[row][col-1]=='O' && !visited[row][col-1]) {
                visited[row][col-1] = 1;
                q.push({row,col-1});
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};