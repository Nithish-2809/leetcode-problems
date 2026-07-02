class Solution {
private:
    bool dfs(const vector<vector<int>>&adj,vector<bool>&visited,
            vector<bool>&inRecursion,int node) {
                visited[node] = true;
                inRecursion[node] = true;

                for(auto it : adj[node]) {
                    if(!visited[it]) {
                        if(dfs(adj,visited,inRecursion,it)) return true;
                    }
                    else if(inRecursion[it]) {
                        return true;
                    }
                }
        inRecursion[node] = false;

        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        

        vector<vector<int>>adj(n);

        for(auto it : prerequisites) {
            int v = it[0];
            int u = it[1];

            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        vector<bool>inRecursion(n,false);

        for(int i=0;i<n;i++) {
            if(!visited[i] && dfs(adj,visited,inRecursion,i)) {
                return false;
            }
        }

    return true;
    }
};