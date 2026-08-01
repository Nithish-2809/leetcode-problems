bool solve(vector<int>& nums, int index, int currSum, int target,
           vector<vector<int>>& dp) {

    if(currSum == target) return true;
    if(index == nums.size() || currSum > target) return false;

    if(dp[index][currSum] != -1)
        return dp[index][currSum];

    bool take = solve(nums, index + 1, currSum + nums[index], target, dp);
    bool notTake = solve(nums, index + 1, currSum, target, dp);

    return dp[index][currSum] = take || notTake;
}

class Solution {
public:
   bool canPartition(vector<int>& nums) {
    int totalSum = 0;

    for(int x : nums)
        totalSum += x;

    if(totalSum % 2)
        return false;

    int target = totalSum / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

    return solve(nums, 0, 0, target, dp);
}
};