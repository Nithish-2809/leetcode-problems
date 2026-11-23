class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyPrice = prices[0];
        int n = prices.size();
        for(int i=1;i<n;i++) {
            int profit = prices[i]-buyPrice;
            maxProfit = max(maxProfit,profit);
            buyPrice = min(buyPrice,prices[i]);
        }

    return maxProfit;
    }
};