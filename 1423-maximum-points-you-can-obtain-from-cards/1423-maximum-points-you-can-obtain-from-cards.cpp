class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;

        int maxSum = 0;
        
        for(int i=0;i<k;i++) {
            leftSum += nums[i];
        }
        maxSum = max(maxSum,leftSum);

        int rightIndex = n-1;
        for(int i=k-1;i>=0;i--) {
            leftSum -= nums[i];
            rightSum += nums[rightIndex];
            rightIndex--;

            maxSum = max(maxSum,leftSum+rightSum);
        }

        return maxSum;
    }
};