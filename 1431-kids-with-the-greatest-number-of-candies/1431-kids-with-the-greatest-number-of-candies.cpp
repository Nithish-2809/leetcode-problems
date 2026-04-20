class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& nums, int extraCandies) {
        
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            maxi = max(maxi,nums[i]);
        }

        vector<bool>ans(n,0);

        for(int i=0;i<n;i++) {
            if(nums[i]+extraCandies>=maxi) {
                ans[i] = true;
            }
            else {
                ans[i] = false;
            }
        }
    return ans;
    }
};