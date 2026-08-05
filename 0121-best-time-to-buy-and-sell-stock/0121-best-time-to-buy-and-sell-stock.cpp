class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int currPrice = prices[0];

        for(int i=1;i<n;i++) {
            int profit = prices[i]-currPrice;
            currPrice = min(currPrice,prices[i]);

            maxProfit = max(maxProfit,profit);
        }
    
    return maxProfit;
    }
};