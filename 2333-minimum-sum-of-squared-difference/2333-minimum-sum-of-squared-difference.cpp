class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int maxi = 0;
        vector<int> diff(n);

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        vector<long long> freq(maxi + 1, 0);

        long long total = 0;

        for(int i = 0; i < n; i++) {
            freq[diff[i]]++;
            total += diff[i];
        }

        if(k >= total) return 0;

        for(int i = maxi; i > 0 && k > 0; i--) {
            long long reduce = min(freq[i], k);

            freq[i] -= reduce;
            freq[i - 1] += reduce;

            k -= reduce;
        }

        long long ans = 0;

        for(int i = 0; i <= maxi; i++) {
            ans += freq[i] * i * i;
        }

        return ans;
    }
};