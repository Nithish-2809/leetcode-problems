class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        int index = 1;

        for(char i='z';i>='a';i--) {
            mp[i] = index;
            index++;
        }

        int ans = 0;

        for(int i=0;i<n;i++) {
            ans = ans + (i+1)*mp[s[i]];
        }

    return ans;
    }
};