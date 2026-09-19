class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);

        if(ultimateParentU == ultimateParentV) return;

        if(rank[ultimateParentU] > rank[ultimateParentV]) {
            parent[ultimateParentV] = ultimateParentU;
        }
        else if(rank[ultimateParentU] < rank[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
        }
        else {
            parent[ultimateParentU] = ultimateParentV;
            rank[ultimateParentV]++;
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras = 0;

        for(auto it : connections) {
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u)==ds.findParent(v)) extras++;
            else ds.unionByRank(u,v);
        }

        int nC = 0;
        for(int i=0;i<n;i++) {
            if(ds.parent[i]==i) nC++;
        }

        int ans = nC-1;

        if(extras>=nC-1) {
            return ans;
        }
        return -1;
    }
};