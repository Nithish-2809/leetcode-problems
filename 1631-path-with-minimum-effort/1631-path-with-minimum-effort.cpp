class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        set<pair<int,pair<int,int>>>st;

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        st.insert({0,{0,0}});
        dist[0][0] = 0;

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};


        while(!st.empty()) {
            auto it = *(st.begin());
            st.erase(st.begin());
            int row = it.second.first;
            int col = it.second.second;
            int diff = it.first;

            if(row==n-1 && col==m-1) return diff;

            for(int i=0;i<4;i++) {
                int newRow = row+dr[i];
                int newCol = col+dc[i];

                if(newRow<=n-1 && newRow>=0 && newCol<=m-1 && newCol>=0) {
                    int newDist = max(abs(heights[newRow][newCol]-heights[row][col]),diff);

                    if(newDist<dist[newRow][newCol]) {
                        if(dist[newRow][newCol]!=INT_MAX) {
                            st.erase({dist[newRow][newCol],{newRow,newCol}});
                        }
                        dist[newRow][newCol] = newDist;
                        st.insert({newDist,{newRow,newCol}});
                    }
                }
            }
        }

    return -1;
    }
};