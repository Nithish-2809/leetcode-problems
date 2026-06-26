class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        map<int, int> mp;
        int cumSum = 0;
        long long validLeftPoints = 0;
        long long ans = 0;

        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                validLeftPoints += mp[cumSum];
                cumSum++;
            } else {
                validLeftPoints -= mp[cumSum-1];
                cumSum--;
            }

            mp[cumSum]++;
            ans += validLeftPoints;
        }

        return ans;
    }
};