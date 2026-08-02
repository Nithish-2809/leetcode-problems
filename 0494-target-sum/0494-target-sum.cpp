class Solution {
public:
    int totalWays(vector<int>& nums, int index, int target,
                  vector<vector<int>>& dp, int OFFSET) {

        if (index == nums.size()) {
            return (target == 0);
        }

        if (abs(target) > OFFSET)
            return 0;

        if (dp[index][target + OFFSET] != -1)
            return dp[index][target + OFFSET];

        int takePlus = totalWays(nums, index + 1, target - nums[index], dp, OFFSET);
        int takeMinus = totalWays(nums, index + 1, target + nums[index], dp, OFFSET);

        return dp[index][target + OFFSET] = takePlus + takeMinus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        int OFFSET = sum;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));

        return totalWays(nums, 0, target, dp, OFFSET);
    }
};