bool isPossible(const vector<int>nums,int mid,int k) {
    int n = nums.size();
    int subarrays = 1;
    int sum = 0;

    for(int i=0;i<n;i++) {
        if(nums[i]>mid) return false;

        if(sum+nums[i]<=mid) sum+= nums[i];
        else {
            subarrays++;
            sum = nums[i];
        }
    }

    return subarrays<=k;
}


class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++) {
            sum += nums[i];
            maxi = max(maxi,nums[i]);
        }

        int low = maxi;
        int high = sum;
        int ans;

        while(low<=high) {
            int mid = low + (high-low)/2;

            if(isPossible(nums,mid,k)) {
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