class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int onesCnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                onesCnt++;
            }
        }

        vector<int> zeroBlocks;

        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int cnt = 0;

                while (i < n && s[i] == '0') {
                    cnt++;
                    i++;
                }

                zeroBlocks.push_back(cnt);
            } 
            else {
                i++;
            }
        }

        int maxi = 0;

        for (int i = 0; i + 1 < zeroBlocks.size(); i++) {
            maxi = max(maxi, zeroBlocks[i] + zeroBlocks[i + 1]);
        }

        return onesCnt + maxi;
    }
};