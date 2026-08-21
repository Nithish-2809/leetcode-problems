class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(vector<int>& coins, long long mid) {
        int n = coins.size();
        long long cnt = 0;

        for(int mask = 1; mask < (1 << n); mask++) {
            long long currLcm = 1;
            bool valid = true;
            int bits = 0;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    bits++;

                    currLcm = lcm(currLcm, (long long)coins[i]);

                    if(currLcm > mid) {
                        valid = false;
                        break;
                    }
                }
            }

            if(!valid) continue;

            if(bits & 1) {
                cnt += mid / currLcm;
            }
            else {
                cnt -= mid / currLcm;
            }
        }

        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1e18;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(countNumbers(coins, mid) >= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};