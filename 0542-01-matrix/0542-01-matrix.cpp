class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    ans[i][j] = 0;
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if(row<n-1 && !visited[row+1][col]) {
                visited[row+1][col] = 1;
                ans[row+1][col] = dist+1;
                q.push({{row+1,col},dist+1});
            }

            if(col<m-1 && !visited[row][col+1]) {
                visited[row][col+1] = 1;
                ans[row][col+1] = dist+1;
                q.push({{row,col+1},dist+1});
            }

            if(row>0 && !visited[row-1][col]) {
                visited[row-1][col] = 1;
                ans[row-1][col] = dist+1;
                q.push({{row-1,col},dist+1});
            }

            if(col>0 && !visited[row][col-1]) {
                visited[row][col-1] = 1;
                ans[row][col-1] = dist+1;
                q.push({{row,col-1},dist+1});
            }
        }

        return ans;
    }
};