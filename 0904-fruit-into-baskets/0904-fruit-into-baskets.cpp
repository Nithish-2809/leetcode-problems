class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freqMap;
        int l = 0;
        int r = 0;
        int maxLen = 0;

        while(r<n) {
            freqMap[nums[r]]++;

            while(freqMap.size()>2) {
                freqMap[nums[l]]--;
                if(freqMap[nums[l]]==0) freqMap.erase(nums[l]);
                l++;
            }

            maxLen = max(maxLen,r-l+1);

            r++;
        }

        return maxLen;
        
    }
};