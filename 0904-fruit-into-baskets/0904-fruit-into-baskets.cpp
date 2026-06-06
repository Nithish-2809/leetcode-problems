class Solution {
public:
    int totalFruit(vector<int>& nums) {
       unordered_map<int,int>mp;
       int n = nums.size();
       int left = 0;
       int right = 0;
       int maxLen = 0;

       while(right<n) {
        mp[nums[right]]++;
        while(mp.size()>2) {
            mp[nums[left]]--;
            if(mp[nums[left]]==0) mp.erase(nums[left]);
            left++;
        }
        maxLen = max(maxLen,right-left+1);
        right++;
       }

       return maxLen;
    }
};