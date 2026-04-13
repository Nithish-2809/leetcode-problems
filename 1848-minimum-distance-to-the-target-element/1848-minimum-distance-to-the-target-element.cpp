class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int ans = -1;

        if(start==0) {
            for(int i=0;i<n;i++) {
                if(nums[i]==target) return abs(i-start);
            }
        }
        else if(start==n-1) {
            for(int i=n-1;i>=0;i--) {
                if(nums[i]==target) return abs(i-start);
            }
        }
        else {
            int upcomingIndex = n;
            for(int i=start;i<n;i++) {
                 if(nums[i]==target) {
                    upcomingIndex = i;
                    break;
                 }
            }

            int backIndex = n;
            for(int i=start;i>=0;i--) {
                 if(nums[i]==target) {
                    backIndex = i;
                    break;
                 }
            }

            if(upcomingIndex == n) return abs(start - backIndex);
            if(backIndex == n) return abs(start - upcomingIndex);

            ans = min(abs(start-backIndex),abs(start-upcomingIndex));
        }
    return ans;
    }
};