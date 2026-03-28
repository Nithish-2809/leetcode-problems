class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            vector<int> hashh(26, 0);

            for(int j = i; j < n; j++) {
                hashh[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for(int k = 0; k < 26; k++) {
                    if(hashh[k] > 0) {
                        maxFreq = max(maxFreq, hashh[k]);
                        minFreq = min(minFreq, hashh[k]);
                    }
                }

                sum += (maxFreq - minFreq);
            }
        }

        return sum;
    }
};