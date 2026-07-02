class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(auto it : prerequisites) {
            int course = it[0];
            int pre = it[1];

            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++) {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;

                if(indegree[it]==0)
                    q.push(it);
            }
        }

        if(ans.size()!=n)
            return {};

        return ans;
    }
};