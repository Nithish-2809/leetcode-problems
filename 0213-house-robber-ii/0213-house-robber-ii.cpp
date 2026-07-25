class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];

        int prev2 = nums[start];
        int prev = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev;

            int curr = max(pick, notPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};