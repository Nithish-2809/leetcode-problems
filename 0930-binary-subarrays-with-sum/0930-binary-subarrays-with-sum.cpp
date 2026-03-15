int findNumberOfSubarrays(vector<int>nums,int k) {
    if(k < 0) return 0;
    int l = 0;
    int r = 0;
    int n = nums.size();
    int sum = 0;
    int cnt = 0;
    while(r<n) {
        sum += nums[r];

        while(sum>k) {
            sum -= nums[l];
            l++;
        }

        if(sum<=k) {
            cnt += (r-l+1);
        }

        r++;
    }

    return cnt;
}




class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        int cnt1 = findNumberOfSubarrays(nums,goal);
        int cnt2 = findNumberOfSubarrays(nums,goal-1);
        
        cnt = cnt1-cnt2;



       return cnt;
    }
};