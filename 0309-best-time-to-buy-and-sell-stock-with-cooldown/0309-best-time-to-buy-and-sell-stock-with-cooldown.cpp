int maximizeProfit(vector<int>prices,int index,bool canBuy,vector<vector<int>>&dp) {
    int n = prices.size();

    if(index>=n) return 0;

    if(dp[index][canBuy]!=-1) return dp[index][canBuy];

    int profit = 0;

    if(canBuy) {
        profit = max(-prices[index]+maximizeProfit(prices,index+1,false,dp),
                    maximizeProfit(prices,index+1,true,dp));
    }
    else {
        profit = max(prices[index]+maximizeProfit(prices,index+2,true,dp),
                        maximizeProfit(prices,index+1,false,dp));
    }

    return dp[index][canBuy] = profit;
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return maximizeProfit(prices,0,true,dp);
    }
};