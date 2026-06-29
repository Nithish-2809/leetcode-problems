class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = INT_MIN;
        double sum = 0;
        for(int i=0;i<k;i++) {
            sum += nums[i];
        }

        maxAvg = sum/k;

        for(int i=k;i<n;i++) {
            sum += nums[i];
            sum -= nums[i-k];

            maxAvg = max(maxAvg,sum/k);
        }
    return maxAvg;
    }
};