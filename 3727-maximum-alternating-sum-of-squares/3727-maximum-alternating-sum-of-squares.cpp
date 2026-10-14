
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                nums[i] = -nums[i];
            }
        }

        sort(nums.begin(), nums.end(), greater<int>());

        long long sum = 0;
        int mid = (n + 1) / 2;

        for(int i = 0; i < mid; i++) {
            sum += 1LL * nums[i] * nums[i];
        }

        for(int i = mid; i < n; i++) {
            sum -= 1LL * nums[i] * nums[i];
        }

        return sum;
    }
};
