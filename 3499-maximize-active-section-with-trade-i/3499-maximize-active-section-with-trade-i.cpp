class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int existingOnes = 0;
        for (char c : s) {
            if (c == '1') existingOnes++;
        }

        vector<int> inactiveBlocks;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                int start = i;
                int cnt = 0;

                while (start < n && s[start] == '0') {
                    start++;
                    cnt++;
                }

                inactiveBlocks.push_back(cnt);
                i = start - 1;
            }
        }

        int maxPairSum = 0;

        for (int i = 0; i + 1 < inactiveBlocks.size(); i++) {
            maxPairSum = max(maxPairSum,
                             inactiveBlocks[i] + inactiveBlocks[i + 1]);
        }

        return existingOnes + maxPairSum;
    }
};