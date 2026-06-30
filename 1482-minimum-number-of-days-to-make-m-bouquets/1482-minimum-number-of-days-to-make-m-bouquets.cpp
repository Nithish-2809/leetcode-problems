bool isPossibleDay(vector<int>nums,int day,int m,int k) {
    int bouquets = 0;
    int flowers = 0;
    int n = nums.size();

    for(int i=0;i<n;i++) {
        if(nums[i]<=day) {
            flowers++;
            if(flowers==k) {
                bouquets++;
                flowers=0;
            }
        }
        else {
            flowers = 0;
        }
    }

    return bouquets>=m;
}






class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if(1LL*k*m>n) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++) {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        int low = mini;
        int high = maxi;
        int ans = 0;

        while(low<=high) {
            int mid = low + (high-low)/2;

            if(isPossibleDay(nums,mid,m,k)) {
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