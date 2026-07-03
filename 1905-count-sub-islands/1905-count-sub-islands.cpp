bool isSubgrid(const vector<vector<int>>& grid1,const vector<vector<int>>& grid2,
                vector<vector<int>>&visited,int i,int j) {

    int n = grid1.size();
    int m = grid1[0].size();

    
    queue<pair<int,int>>q;
    q.push({i,j});

    bool result = true;

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(grid1[row][col]==0) {
            result = false;
        }

        //down
        if(row<n-1 && !visited[row+1][col] && grid2[row+1][col]==1) {
            q.push({row+1,col});
            visited[row+1][col] = 1;
        }

        //up
        if(row>0 && !visited[row-1][col] && grid2[row-1][col]==1) {
            q.push({row-1,col});
            visited[row-1][col] = 1;
        }

        //right
        if(col<m-1 && !visited[row][col+1] && grid2[row][col+1]==1) {
            q.push({row,col+1});
            visited[row][col+1] = 1;
        }

        //left
        if(col>0 && !visited[row][col-1] && grid2[row][col-1]==1) {
            q.push({row,col-1});
            visited[row][col-1] = 1;
        }

    }

    

    
    return result; 
}



class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int subgrids = 0;

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid2[i][j]) {
                    visited[i][j] = 1;
                    if(isSubgrid(grid1,grid2,visited,i,j)) subgrids++;
                }
            }
        }


    return subgrids;
    }
};