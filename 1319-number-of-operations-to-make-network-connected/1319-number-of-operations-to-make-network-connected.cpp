class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultp_u = findUltimateParent(u);
        int ultp_v = findUltimateParent(v);

        if (ultp_u == ultp_v) {
            return;
        }

        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        } else if (rank[ultp_v] < rank[ultp_u]) {
            parent[ultp_v] = ultp_u;
        } else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);
        int extraConnections = 0;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.findUltimateParent(u) == ds.findUltimateParent(v)) {
                extraConnections++;
            } else {
                ds.unionByRank(u, v);
            }
        }

        int numberOfComponents = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUltimateParent(i) == i) {
                numberOfComponents++;
            }
        }

        int ans = numberOfComponents - 1;

        if (extraConnections >= ans)
            return ans;

        return -1;
    }
};