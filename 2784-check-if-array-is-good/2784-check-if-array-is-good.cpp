class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> hashh(n, 0);

        for (auto it : nums) {
            if (it >= n) return false;
            hashh[it]++;
        }

        bool isGood = true;

        for (int i = 1; i < n - 1; i++) {
            if (hashh[i] != 1) isGood = false;
        }

        if (hashh[n - 1] != 2) isGood = false;

        return isGood;
    }
};