class Solution {
public:
    int solve(vector<int>& nums, int index, int currSum,
              vector<vector<int>>& dp, int offset) {

        if(index == nums.size()) {
            return (currSum == 0);
        }

        if(currSum < -offset || currSum > offset) {
            return 0;
        }

        if(dp[index][currSum + offset] != -1) {
            return dp[index][currSum + offset];
        }

        int add = solve(nums, index + 1,
                        currSum - nums[index], dp, offset);

        int sub = solve(nums, index + 1,
                        currSum + nums[index], dp, offset);

        return dp[index][currSum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        for(int num : nums) {
            totalSum += num;
        }

        if(abs(target) > totalSum) return 0;

        int offset = totalSum;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(2 * totalSum + 1, -1)
        );

        return solve(nums, 0, target, dp, offset);
    }
};