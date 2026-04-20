class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;

        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[i]!=nums[j]) maxi = max(maxi,j-i);
            }
        }

        return maxi;
    }
};