class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // down
            if(row + 1 < n &&
               distance[row + 1][col] > distance[row][col] + 1) {
                distance[row + 1][col] = distance[row][col] + 1;
                q.push({row + 1, col});
            }

            // up
            if(row - 1 >= 0 &&
               distance[row - 1][col] > distance[row][col] + 1) {
                distance[row - 1][col] = distance[row][col] + 1;
                q.push({row - 1, col});
            }

            // right
            if(col + 1 < m &&
               distance[row][col + 1] > distance[row][col] + 1) {
                distance[row][col + 1] = distance[row][col] + 1;
                q.push({row, col + 1});
            }

            // left
            if(col - 1 >= 0 &&
               distance[row][col - 1] > distance[row][col] + 1) {
                distance[row][col - 1] = distance[row][col] + 1;
                q.push({row, col - 1});
            }
        }

        return distance;
    }
};