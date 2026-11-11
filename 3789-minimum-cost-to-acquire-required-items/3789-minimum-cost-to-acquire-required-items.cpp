
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long common = min(need1, need2);

        long long ans = common * min(costBoth, cost1 + cost2);

        int rem1 = need1 - common;
        int rem2 = need2 - common;

        ans += 1LL*rem1 * min(cost1, costBoth);
        ans += 1LL*rem2 * min(cost2, costBoth);

        return ans;
    }
};
