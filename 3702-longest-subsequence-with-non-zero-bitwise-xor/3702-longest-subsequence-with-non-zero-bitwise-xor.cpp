class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorResult = 0;
        int zerosCnt = 0;

        for(int i=0;i<n;i++) {
            xorResult ^= nums[i];
            if(nums[i]==0) zerosCnt++;
        }

        if(zerosCnt==n) return 0;

        if(xorResult==0) return n-1;

        return n;
    }
};