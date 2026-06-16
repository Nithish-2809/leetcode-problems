class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

    
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }

        // Mark existing numbers
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);

            if (num >= 1 && num <= n) {
                int idx = num - 1;

                if (nums[idx] > 0)
                    nums[idx] = -nums[idx];
            }
        }

        // First positive index
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};