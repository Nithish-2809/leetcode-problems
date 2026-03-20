class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxPrefix(n);
        vector<int>maxSuffix(n);

        maxPrefix[0] = nums[0];
        for(int i=1;i<n;i++) {
            maxPrefix[i] = max(maxPrefix[i-1],nums[i]);
        }
        maxSuffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            maxSuffix[i] = max(maxSuffix[i+1],nums[i]);
        }

        int total = 0;

        for(int i=0;i<n;i++) {
            if(nums[i]<maxPrefix[i] && nums[i]<maxSuffix[i]) {
                total += min(maxPrefix[i],maxSuffix[i])-nums[i];
            }
        }

        return total;
    }
};