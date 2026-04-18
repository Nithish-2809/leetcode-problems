class Solution {
public:
    int mirrorDistance(int n) {
        int dist = 0;

        int rev = 0;
        int temp = n;
        while(temp>0) {
            int ld = temp%10;
            rev = rev*10 + ld;
            temp /=10;
        }

        return abs(rev-n);
    }
};