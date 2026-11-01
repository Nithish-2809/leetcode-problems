int numberOfSubbarays(vector<int>nums,int k) {
    int n = nums.size();
    int l = 0;
    int r = 0;
    int cnt = 0;
    long long sum = 0;
    if(k<0) return 0;

    while(r<n) {
        sum += nums[r];

        while(sum>k) {
            sum -= nums[l];
            l++;
        }

        cnt += (r-l+1);
        r++;
    }

    return cnt;
}







class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return numberOfSubbarays(nums,goal)-numberOfSubbarays(nums,goal-1);
    }
};