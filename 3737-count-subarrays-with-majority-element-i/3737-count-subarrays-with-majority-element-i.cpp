class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target);
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int freq = pref[j + 1] - pref[i];

                if(freq * 2 > (j - i + 1)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};