void getAllPaths(const vector<vector<int>>& graph, vector<vector<int>>&ans,
                 vector<int>&path,int n,int node) {

        
    if(node==n-1) {
        ans.push_back(path);
        return;
    }

    for(auto it : graph[node]) {
        path.push_back(it);
        getAllPaths(graph,ans,path,n,it);
        path.pop_back();
    }

}




class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>ans;
        vector<int>path;
        int n = graph.size();
        path.push_back(0);

        getAllPaths(graph,ans,path,n,0);


    return ans;
    }
};