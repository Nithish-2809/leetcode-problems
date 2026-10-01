int countNumberOfSubarrays(vector<int>nums,int k) {
    int n = nums.size();
    int odds = 0;
    int cnt = 0;
    int l = 0;
    int r = 0;

    while(r<n) {
        if(nums[r]%2==1) odds++;

        while(odds>k) {
            if(nums[l]%2==1) odds--;
            l++;
        }
        cnt += (r-l+1);

        r++;
    }

    return cnt;
}


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return countNumberOfSubarrays(nums,k)-countNumberOfSubarrays(nums,k-1);
    }
};