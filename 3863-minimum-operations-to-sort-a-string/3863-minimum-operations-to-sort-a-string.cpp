class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        bool isSorted = true;
        char maxi = s[0], mini = s[0];

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                isSorted = false;
            }

            maxi = max(maxi, s[i]);
            mini = min(mini, s[i]);
        }

        if (isSorted) return 0;
        if (n == 2) return -1;

        int maxCount = 0, minCount = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == maxi) maxCount++;
            if (s[i] == mini) minCount++;
        }

        if (s[0] == maxi && s[n - 1] == mini &&
            maxCount == 1 && minCount == 1) {
            return 3;
        }

        if (s[0] == mini || s[n - 1] == maxi) {
            return 1;
        }

        return 2;
    }
};