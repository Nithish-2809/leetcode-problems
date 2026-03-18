class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> hashh(256, 0);

        // store frequency of t
        for(int i = 0; i < m; i++) {
            hashh[t[i]]++;
        }

        int l = 0, r = 0;
        int count = m;  // how many chars we still need
        int minLen = INT_MAX;
        int startIndex = 0;

        while(r < n) {
    
            if(hashh[s[r]] > 0) {
                count--;
            }
            hashh[s[r]]--;
            
            while(count == 0) {
                
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }
                hashh[s[l]]++;
                if(hashh[s[l]] > 0) {
                    count++;
                }
                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};