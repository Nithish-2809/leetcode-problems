class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>hashh(1e6,0);
        
        for(int i=0;i<n;i++) {
            if(nums[i]>=0 && nums[i]<1e6) {
                hashh[nums[i]]++;
            }
        }

        for(int i=1;i<hashh.size();i++) {
            if(hashh[i]==0) return i;
        }

    return -1;
    }
};