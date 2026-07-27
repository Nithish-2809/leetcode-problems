class Solution {
public:
    bool solve(int index, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if (index >= n - 1)
            return true;

        if (dp[index] != -1)
            return dp[index];

        int jumpSize = nums[index];

        for (int jump = 1; jump <= jumpSize; jump++) {
            if (solve(index + jump, nums, dp))
                return dp[index] = true;
        }

        return dp[index] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};