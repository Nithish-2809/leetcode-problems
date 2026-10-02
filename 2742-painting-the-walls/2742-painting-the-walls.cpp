int calculateMinCost(const vector<int>&cost,const vector<int>&time,int index,int wallsLeft,vector<vector<int>>&dp) {
    int n = cost.size();
    if(wallsLeft<=0) return 0;

    if(index==n) {
        return 1e9;
    }

    if(dp[index][wallsLeft]!=-1) return dp[index][wallsLeft];


    int paint = cost[index] + calculateMinCost(cost,time,index+1,wallsLeft-1-time[index],dp);
    int notPaint = calculateMinCost(cost,time,index+1,wallsLeft,dp);

    return dp[index][wallsLeft] = min(paint,notPaint);

}


class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n = cost.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return calculateMinCost(cost,time,0,n,dp);
    }
};