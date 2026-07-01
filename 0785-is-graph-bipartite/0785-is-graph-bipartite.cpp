class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color) {

        for(int neighbor : graph[node]) {

            if(color[neighbor] == -1) {
                color[neighbor] = !color[node];
                
                if(!dfs(graph, neighbor, color))
                    return false;
            }
            else if(color[neighbor] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {

            if(color[i] == -1) {

                color[i] = 0;

                if(!dfs(graph, i, color))
                    return false;
            }
        }

        return true;
    }
};