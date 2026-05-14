class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());

        if(n != maxi + 1) return false;

        vector<int> freq(maxi + 1, 0);

        for(int x : nums) {
            if(x < 1 || x > maxi) return false;
            freq[x]++;
        }

        for(int i = 1; i < maxi; i++) {
            if(freq[i] != 1) return false;
        }

        return freq[maxi] == 2;
    }
};