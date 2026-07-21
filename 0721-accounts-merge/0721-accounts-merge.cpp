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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        map<string, int> mailNode;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mailNode.find(mail) == mailNode.end()) {
                    mailNode[mail] = i;
                } else {
                    ds.unionByRank(i, mailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);

        for (auto it : mailNode) {
            string mail = it.first;
            int node = it.second;

            int parent = ds.findUltimateParent(node);

            mergedMail[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].size() == 0)
                continue;

            // sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto mail : mergedMail[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};