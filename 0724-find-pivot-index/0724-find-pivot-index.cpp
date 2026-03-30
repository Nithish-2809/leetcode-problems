class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i=0;i<n;i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;
        int index = -1;

        for(int i=0;i<n;i++) {
            int rightSum = totalSum-leftSum-nums[i];

            if(leftSum==rightSum) {
                index = i;
                break;
            }

            leftSum += nums[i];
        }

        return index;
    }
};