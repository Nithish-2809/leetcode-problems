class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++) {
            if(nums[i]<=0 || nums[i]>n) nums[i]=0;
        }

        vector<int>hashh(n+1,0);

        for(int i=0;i<n;i++) {
            hashh[nums[i]]++;
        }

        for(int i=1;i<hashh.size();i++) {
            if(hashh[i]==0) return i;
        }

    return n+1;
    }
};