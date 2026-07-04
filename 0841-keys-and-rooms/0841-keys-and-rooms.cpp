void dfs(vector<vector<int>>& rooms,vector<bool>&visited,int node) {
    visited[node] = true;

    for(auto it : rooms[node]) {
        if(!visited[it]) {
            dfs(rooms,visited,it);
        }
    }
}




class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);

        dfs(rooms,visited,0);
        
        for(auto it : visited) {
            if(it==false) return false;
        }

    return true;
    }
};