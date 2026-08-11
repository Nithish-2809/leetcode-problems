int maximumProfit(vector<int>&prices,int index,int k,bool canBuy,vector<vector<vector<int>>>&dp) {
    if(k==0) return 0;
    int n = prices.size();
    if(index==n) return 0;

    if(dp[index][k][canBuy]!=-1) return dp[index][k][canBuy];

    int profit = 0;

    if(canBuy) {
        profit += max(-prices[index]+maximumProfit(prices,index+1,k,false,dp),
                        maximumProfit(prices,index+1,k,true,dp));
    }
    else {
        profit += max(prices[index]+maximumProfit(prices,index+1,k-1,true,dp),
                        maximumProfit(prices,index+1,k,false,dp));
    }   

    return dp[index][k][canBuy] = profit;
    
}


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));


        return maximumProfit(prices,0,k,true,dp);
    }
};