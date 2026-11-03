class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int,int>>> adj(n+1);

        for(auto it : times) {
            int src = it[0];
            int dest = it[1];
            int time = it[2];

            adj[src].push_back({dest,time});
        }

        vector<int>dist(n+1,INT_MAX);

        dist[k] = 0;

        set<pair<int,int>>st;
        st.insert({0,k});

        while(!st.empty()) {

            int time = st.begin()->first;
            int node = st.begin()->second;

            st.erase(st.begin());

            for(auto it : adj[node]) {

                int adjNode = it.first;
                int edgeTime = it.second;

                if(time + edgeTime < dist[adjNode]) {

                    dist[adjNode] = time + edgeTime;

                    st.insert({dist[adjNode],adjNode});
                }
            }
        }

        int maxi = -1;

        for(int i=1;i<=n;i++) {

            if(dist[i] == INT_MAX) return -1;

            maxi = max(maxi,dist[i]);
        }

        return maxi;
    }
};