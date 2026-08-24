class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k == 0) return 0;

        unordered_map<int,int> mp;
        int l = 0;
        int cnt = 0;

        for(int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;

            while(mp.size() > k) {
                mp[nums[l]]--;

                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l++;
            }

            cnt += r - l + 1;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};