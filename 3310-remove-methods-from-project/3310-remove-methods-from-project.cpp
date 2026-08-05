class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for(auto &it : invocations) {
            graph[it[0]].push_back(it[1]);
        }

        vector<bool> suspicious(n, false);

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nei : graph[node]) {
                if(!suspicious[nei]) {
                    suspicious[nei] = true;
                    q.push(nei);
                }
            }
        }

        bool canRemove = true;

        for(auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if(!suspicious[u] && suspicious[v]) {
                canRemove = false;
                break;
            }
        }

        vector<int> ans;

        if(!canRemove) {
            for(int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(!suspicious[i]) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};