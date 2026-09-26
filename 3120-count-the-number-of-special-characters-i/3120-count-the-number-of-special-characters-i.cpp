class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>hashhh(52,0);

        int n = word.length();

        for(auto ch : word) {
            if(ch >= 'a' && ch <= 'z')
                hashhh[ch - 'a']++;
            else
                hashhh[ch - 'A' + 26]++;
        }

        int cnt = 0;

        for(int i=0;i<26;i++) {
            if(hashhh[i]>0 &&hashhh[i+26]>0) cnt++;
        }

    return cnt;
    }
};