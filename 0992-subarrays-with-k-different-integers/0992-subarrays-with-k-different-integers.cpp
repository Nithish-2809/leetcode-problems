int cntSubarrays(vector<int>nums,int k) {
    int l = 0;
    int r = 0;
    int n = nums.size();
    int cnt = 0;
    unordered_map<int,int>checkMap;

    while(r<n) {
        checkMap[nums[r]]++;

        while(checkMap.size()>k) {
            checkMap[nums[l]]--;
            if(checkMap[nums[l]]==0) {
                checkMap.erase(nums[l]);
            }
            l++;
        }
        cnt += r-l+1;
        r++;
    }

    return cnt;
}


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return cntSubarrays(nums,k)-cntSubarrays(nums,k-1);
        
    }
};