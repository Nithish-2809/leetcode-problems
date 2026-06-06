class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int>ans;

        for(int i=0;i<n;i++) {
            sum += nums[i];
        }
        int leftSum = 0;
        ans.push_back(abs(sum-nums[0]));

        for(int i=1;i<n;i++) {
            leftSum += nums[i-1];
            int rightSum = sum-leftSum-nums[i];
            ans.push_back(abs(leftSum-rightSum));
        }

        return ans;
    }
};