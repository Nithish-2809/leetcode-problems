class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        unordered_map<char,int>mp;
        int cnt = 0;

        while(r<n) {
            mp[s[r]]++;

            while(mp.find('a')!=mp.end() && mp.find('b')!=mp.end() && mp.find('c')!=mp.end()) {
                cnt += (n-r);
                mp[s[l]]--;
                if(mp[s[l]]==0) {
                    mp.erase(s[l]);
                }
                l++;
            }

            r++;
        }

    return cnt;
    }
};