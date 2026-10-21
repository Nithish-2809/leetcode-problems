class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int balloons = 0;
        int n = text.size();
        vector<int>hashh(26,0);

        for(int i=0;i<n;i++) {
            hashh[text[i]-'a']++;
        }

        while(hashh[1]>0 && hashh[0]>0 && hashh[11]>1 && hashh[14]>1 && hashh[13]>0) {
            hashh[1]--;
            hashh[0]--;
            hashh[11] -= 2;
            hashh[14] -= 2;
            hashh[13]--;
            balloons++;
        }

    return balloons;
    }
};