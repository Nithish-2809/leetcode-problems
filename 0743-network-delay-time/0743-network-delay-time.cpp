class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        // {time, node}
        set<pair<int,int>> st;

        vector<int> timeTaken(n + 1, INT_MAX);

        timeTaken[k] = 0;
        st.insert({0, k});

        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(st.begin());

            int time = it.first;
            int currNode = it.second;

            for (auto neigh : adj[currNode]) {
                int node = neigh.first;
                int edgeWeight = neigh.second;

                if (time + edgeWeight < timeTaken[node]) {
                    if (timeTaken[node] != INT_MAX) {
                        st.erase({timeTaken[node], node});
                    }

                    timeTaken[node] = time + edgeWeight;
                    st.insert({timeTaken[node], node});
                }
            }
        }

        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            if (timeTaken[i] == INT_MAX)
                return -1;

            maxi = max(maxi, timeTaken[i]);
        }

        return maxi;
    }
};