class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        for(int i=0;i<k;i++) {
            sum += nums[i];
        }

        double maxSum = sum;

        int j = 0;

        for(int i=k;i<n;i++) {
            sum += nums[i];
            sum -= nums[j];
            j++;

            maxSum = max(maxSum,sum);
        }

        return maxSum/k;
    }
};