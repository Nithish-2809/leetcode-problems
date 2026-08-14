class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        vector<int>hashh(26,0);
        int maxLen = 0;


        while(r<n) {
            hashh[s[r]-'a']++;

            while(hashh[s[r]-'a']>2) {
                hashh[s[l]-'a']--;
                l++;
            }

            maxLen = max(maxLen,r-l+1);

            r++;
        }

    return maxLen;
    }
};