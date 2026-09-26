class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        int n = nums.size();

        double sum = 0;

        for(int i=0;i<k;i++) {
            sum += nums[i];
        }

        maxAvg = max(maxAvg,sum/k);

        for(int i=k;i<n;i++) {
            sum += nums[i];
            sum -= nums[i-k];
            maxAvg = max(maxAvg,sum/k);
        }

    return maxAvg;
    }
};