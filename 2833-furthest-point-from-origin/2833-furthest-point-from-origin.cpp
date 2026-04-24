class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n = s.length();
        int leftCount = 0;
        int rightCount = 0;

        for(int i=0;i<n;i++) {
            if(s[i]=='L') leftCount++;
            else if(s[i]=='R') rightCount++;
        }

        int dist = 0;
        if(leftCount>rightCount) {
            for(int i=0;i<n;i++) {
                if(s[i]=='_' || s[i]=='L')  {
                    dist--;
                }
                else {
                    dist++;
                }
            }
        }
        else {
            for(int i=0;i<n;i++) {
                if(s[i]=='_' || s[i]=='R')  {
                    dist++;
                }
                else {
                    dist--;
                }
            }
        }


        return abs(dist);
    }
};