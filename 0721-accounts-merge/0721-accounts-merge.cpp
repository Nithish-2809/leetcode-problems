class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if (ult_u == ult_v) return;

        if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_v] < rank[ult_u]) {
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mailMap;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mailMap.find(mail) == mailMap.end()) {
                    mailMap[mail] = i;
                }
                else {
                    ds.unionByRank(i, mailMap[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(n);

        for (auto it : mailMap) {
            string mail = it.first;
            int node = it.second;

            int parent = ds.findUltimateParent(node);

            mergedMails[parent].push_back(mail);
        }

        vector<vector<string>> finalAccounts;

        for (int i = 0; i < n; i++) {
            if (mergedMails[i].empty()) continue;

            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto mail : mergedMails[i]) {
                temp.push_back(mail);
            }

            finalAccounts.push_back(temp);
        }

        return finalAccounts;
    }
};