class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int>freq(26,0);

        for(auto it : word) {
            freq[it-'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());

        int totalClicks = 0;

        for(int i=0;i<26;i++) {
            int cnt = freq[i];
            if(cnt==0) break;
            int clicks = (i/8 + 1);
            totalClicks += cnt*clicks;
        }
    return totalClicks;
    }
};