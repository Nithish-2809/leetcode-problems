class Solution {
public:
    long long minimumSteps(string s) {
        long long minSwaps = 0;
        long long zeroCnt = 0;

        int n = s.length();

        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') zeroCnt++;
            else minSwaps += zeroCnt;
        }

    return minSwaps;
    }
};