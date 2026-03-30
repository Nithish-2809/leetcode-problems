class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n,0);
        vector<int>suffixSum(n,0);

        int sum = 0;
        

        for(int i=0;i<n;i++) {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        sum = 0;
        for(int i=n-1;i>=0;i--) {
            sum += nums[i];
            suffixSum[i] = sum;
        }

        int index = -1;
        for(int i=0;i<n;i++) {
            if(prefixSum[i]==suffixSum[i]) {
                index = i;
                break;
            }
        }

    return index;
    }
};