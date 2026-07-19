class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // {cost, node}
        set<pair<int,int>> st;
        st.insert({0,0});

        vector<int> visited(n,0);

        int ans = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            st.erase(st.begin());

            int cost = it.first;
            int node = it.second;

            if(visited[node]) continue;

            visited[node] = 1;
            ans += cost;

            for(int i=0;i<n;i++) {
                if(!visited[i]) {
                    int wt = abs(points[node][0]-points[i][0]) +
                             abs(points[node][1]-points[i][1]);

                    st.insert({wt,i});
                }
            }
        }

        return ans;
    }
};