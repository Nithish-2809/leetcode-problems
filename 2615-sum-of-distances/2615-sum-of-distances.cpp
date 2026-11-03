class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for(auto it : mp) {
            vector<int>& indices = it.second;
            int k = indices.size();

            long long sum = 0;

            for(int idx : indices) {
                sum += idx;
            }

            long long leftSum = 0;

            for(int j = 0; j < k; j++) {
                long long i = indices[j];

                long long left = i * j - leftSum;
                long long right = (sum - leftSum - i) - i * (k - j - 1);

                ans[i] = left + right;

                leftSum += i;
            }
        }

        return ans;
    }
};