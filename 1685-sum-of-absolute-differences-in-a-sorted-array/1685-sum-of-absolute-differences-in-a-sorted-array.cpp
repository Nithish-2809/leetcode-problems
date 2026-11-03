class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        int leftSum = 0;
        int rightSum = 0;
        vector<int>ans(n);

        for(int i=0;i<n;i++) {
            rightSum = sum-leftSum-nums[i];
            ans[i] = (nums[i]*i-leftSum)+(rightSum-nums[i]*(n-i-1));
            leftSum += nums[i];
        }

    return ans;
    }
};