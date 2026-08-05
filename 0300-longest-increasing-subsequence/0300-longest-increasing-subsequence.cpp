int longestLIS(vector<int>& nums, int index, int prev_index,
               vector<vector<int>>& dp) {

    int n = nums.size();

    if(index == n) return 0;

    if(dp[index][prev_index + 1] != -1)
        return dp[index][prev_index + 1];

    int not_pick = longestLIS(nums, index + 1, prev_index, dp);

    int pick = 0;

    if(prev_index == -1 || nums[index] > nums[prev_index]) {
        pick = 1 + longestLIS(nums, index + 1, index, dp);
    }

    return dp[index][prev_index + 1] = max(pick, not_pick);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return longestLIS(nums, 0, -1, dp);
    }
};