class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0]=grid[0][0];

        pq.push({grid[0][0],0,0});

        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()){

            auto curr=pq.top();
            pq.pop();

            int cost=curr[0];
            int i=curr[1];
            int j=curr[2];

            if(i==n-1 && j==n-1)
                return cost;

            if(cost>dist[i][j])
                continue;

            for(auto &d:dir){

                int x=i+d[0];
                int y=j+d[1];

                if(x>=0 && x<n && y>=0 && y<n){

                    int newCost=max(cost,grid[x][y]);

                    if(newCost<dist[x][y]){

                        dist[x][y]=newCost;
                        pq.push({newCost,x,y});
                    }
                }
            }
        }

        return -1;
    }
};