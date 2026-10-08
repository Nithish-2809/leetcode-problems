bool isPossible(vector<int>nums,int mid,int m,int k) {
    int n = nums.size();
    int boqs = 0;
    int flowers = 0;

    for(int i=0;i<n;i++) {
        if(nums[i]<=mid) {
            flowers++;
            if(flowers==k) {
                flowers = 0;
                boqs++;
            }
        }
        else {
            flowers = 0;
        }
    }

    return boqs>=m;
}




class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*k*m>n) return -1;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++) {
            maxi = max(maxi,bloomDay[i]);
        }

        int low = 0;
        int high = maxi;
        int ans = -1;

        while(low<=high) {
            int mid = low + (high-low)/2;

            if(isPossible(bloomDay,mid,m,k)) {
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