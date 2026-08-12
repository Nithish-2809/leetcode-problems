
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        unordered_map<int,int>mp;

        int left = 0;
        int right  = 0;

        while(right<n) {
            mp[nums[right]]++;

             while (mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }

            maxLen = max(maxLen,right-left+1);

            right++;
        }

    return maxLen;
    }
};