class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: store all indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // Step 2: process each group
        for(auto &it : mp) {
            vector<int> &v = it.second;
            int m = v.size();

            // prefix pass
            long long prefixSum = 0;
            for(int i = 0; i < m; i++) {
                ans[v[i]] += (long long)v[i] * i - prefixSum;
                prefixSum += v[i];
            }

            // suffix pass
            long long suffixSum = 0;
            for(int i = m - 1; i >= 0; i--) {
                ans[v[i]] += suffixSum - (long long)v[i] * (m - 1 - i);
                suffixSum += v[i];
            }
        }

        return ans;
    }
};