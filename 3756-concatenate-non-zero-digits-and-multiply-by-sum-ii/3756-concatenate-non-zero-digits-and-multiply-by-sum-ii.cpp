class Solution {
public:
    const int MOD = 1000000007;

    int firstGreaterEqual(vector<int>& pos, int target) {
        int low = 0;
        int high = pos.size() - 1;
        int ans = pos.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (pos[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int firstGreater(vector<int>& pos, int target) {
        int low = 0;
        int high = pos.size() - 1;
        int ans = pos.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (pos[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> prefixHash(m + 1, 0);
        vector<long long> prefixSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefixHash[i + 1] = (prefixHash[i] * 10 + digit[i]) % MOD;
            prefixSum[i + 1] = prefixSum[i] + digit[i];
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {

            int l = queries[i][0];
            int r = queries[i][1];

            int L = firstGreaterEqual(pos, l);
            int R = firstGreater(pos, r);

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L;

            long long value = prefixHash[R];
            value = (value - (prefixHash[L] * pow10[len]) % MOD + MOD) % MOD;

            long long sum = prefixSum[R] - prefixSum[L];

            ans.push_back((value * (sum % MOD)) % MOD);
        }

        return ans;
    }
};