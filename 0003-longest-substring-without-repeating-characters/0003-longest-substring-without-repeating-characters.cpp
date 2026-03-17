class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.length();

       int l = 0;
       int r = 0;
       unordered_map<char,int>freqMap;
       int maxLen = 0;
       
       while(r<n) {
            freqMap[s[r]]++;
            while(freqMap[s[r]]>1) {
                freqMap[s[l]]--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
       }

       return maxLen;
    }
};