class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        set<pair<int,pair<int,int>>> st;

        dist[0][0] = 0;
        st.insert({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1)
                return effort;

            for(int k=0;k<4;k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m) {

                    int currDiff =
                        abs(heights[row][col] - heights[nr][nc]);

                    int newEffort = max(effort, currDiff);

                    if(newEffort < dist[nr][nc]) {

                        if(dist[nr][nc] != INT_MAX)
                            st.erase({dist[nr][nc], {nr,nc}});

                        dist[nr][nc] = newEffort;
                        st.insert({newEffort,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};