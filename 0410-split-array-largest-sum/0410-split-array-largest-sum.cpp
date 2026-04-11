bool isMinimumPossible(vector<int>nums,int mid,int k) {
    int n = nums.size();
    int sum = 0;
    int subarrays = 1;

    for(int i=0;i<n;i++) {
        if(sum+nums[i]>mid) {
            subarrays++;
            sum = nums[i];
        }
        else {
            sum += nums[i];
        }
    }


    return subarrays<=k;
}







class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = INT_MIN;
        int sum = 0;

        for(int i=0;i<n;i++) {
            maxi = max(maxi,nums[i]);
            sum += nums[i];
        }

        int low = maxi;
        int high = sum;


        int ans = -1;

        while(low<=high) {
            int mid = low + (high-low)/2;

            if(isMinimumPossible(nums,mid,k)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return ans;
    }
};