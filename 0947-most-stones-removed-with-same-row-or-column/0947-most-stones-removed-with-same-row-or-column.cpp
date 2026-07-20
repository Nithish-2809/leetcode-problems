class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultp_u = findUltimateParent(u);
        int ultp_v = findUltimateParent(v);

        if (ultp_u == ultp_v)
            return;

        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        }
        else if (rank[ultp_v] < rank[ultp_u]) {
            parent[ultp_v] = ultp_u;
        }
        else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0;
        int maxCol = 0;

        for (auto &it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);

        unordered_set<int> nodes;

        for (auto &it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1;

            ds.unionByRank(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for (auto node : nodes) {
            if (ds.findUltimateParent(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};