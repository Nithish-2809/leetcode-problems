class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto it : nums) {
            mini = min(mini,it);
            maxi = max(maxi,it);
        }

        return 1LL*(maxi-mini)*k;
    }
};