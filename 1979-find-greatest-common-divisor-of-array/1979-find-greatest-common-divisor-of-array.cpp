class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto it : nums) {
            mini = min(mini,it);
            maxi = max(maxi,it);
        }

    return __gcd(maxi,mini);
    }
};