class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        
        for(auto it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<int>visited(n,0);

        queue<int>q;

        q.push(k);
        visited[k] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                if(!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        bool allMethods = false;

        for(auto it : invocations) {
            int u = it[0];
            int v = it[1];

            if(!visited[u] && visited[v]) allMethods = true;
        }

        vector<int>ans;

        if(allMethods) {
            for(int i=0;i<n;i++) {
                ans.push_back(i);
            }
        }
        else {
            for(int i=0;i<n;i++) {
                if(!visited[i]) {
                    ans.push_back(i);
                }
            }
        }

    return ans;
    }
};