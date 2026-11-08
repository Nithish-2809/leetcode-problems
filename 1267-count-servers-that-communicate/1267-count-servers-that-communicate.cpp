class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>communicate(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
               if(grid[i][j]==1) {
                int row = i;
                int col = j;
                
                for(int k=0;k<m;k++) {
                    if(grid[row][k]==1 && k!=col) communicate[row][k]=1;
                }

                for(int k=0;k<n;k++) {
                    if(grid[k][col]==1 && k!=row) communicate[k][col]=1;
                }
               }
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(communicate[i][j]==1) cnt++;
            }
        }

    return cnt;
    }
};