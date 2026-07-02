bool dfs(const vector<vector<int>>&graph,vector<bool>&visited,
         vector<bool>&inRecursion,int node) {
            visited[node] = true;
            inRecursion[node] = true;

            for(auto it : graph[node]) {
                if(!visited[it]) {
                    if(dfs(graph,visited,inRecursion,it)) {
                        return true;
                    }
                }
                else if(inRecursion[it]) {
                    return true;
                }
            }
        
        inRecursion[node] = false;


        return false;

}




class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool>visited(n,false);
        vector<bool>inRecursion(n,false);

        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(graph,visited,inRecursion,i);
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++) {
            if(!inRecursion[i]) {
                ans.push_back(i);
            }
        }

    return ans;
    }
};