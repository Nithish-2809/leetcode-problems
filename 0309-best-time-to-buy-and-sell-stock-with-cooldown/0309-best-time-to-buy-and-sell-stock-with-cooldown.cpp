int maximimProfit(vector<int>&prices,int index,bool toBuy,vector<vector<int>>&dp) {

    int n = prices.size();
    if(index>=n) return 0;


    if(dp[index][toBuy]!=-1) return dp[index][toBuy];

    if(toBuy) {
        //buy
        return max(
            -prices[index]+maximimProfit(prices,index+1,false,dp),
            maximimProfit(prices,index+1,true,dp)
            );
    }
    else {
        //sell
        return dp[index][toBuy] = max(
            prices[index]+maximimProfit(prices,index+2,true,dp),
            maximimProfit(prices,index+1,false,dp)
        );
    }

    return dp[index][toBuy] = -1;
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
    return maximimProfit(prices,0,true,dp);
    }
};