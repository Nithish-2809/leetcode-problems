
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            int len1 = dp[x] + 1;
            int len2 = dp[x - 1] + 1;

            dp[x + 1] = max(dp[x + 1], len1);
            dp[x] = max(dp[x], len2);

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};
