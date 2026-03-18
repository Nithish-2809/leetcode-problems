class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char,int>freqMap;
        int maxLen = 0;
        int maxFreq = 0;
        int l = 0;
        int r = 0;

        while(r<n) {
            freqMap[s[r]]++;

            maxFreq = max(maxFreq,freqMap[s[r]]);

            if((r-l+1)-maxFreq>k) {
                freqMap[s[l]]--;
                maxFreq = 0;
                for(auto it : freqMap) {
                    maxFreq = max(maxFreq,it.second);
                }
                l++;
            }
            if((r-l+1)-maxFreq<=k) {
                maxLen = max(maxLen,r-l+1);
            }
            r++;
        }

        return maxLen;
    }
};