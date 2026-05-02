bool isGood(int n) {
    bool changed = false;
    while(n>0) {
        int ld = n%10;

        if(ld==3 || ld==7 || ld==4) return false;

        if(ld == 2 || ld == 5 || ld == 6 || ld == 9) changed = true;

        n /= 10; 
    }

    return changed;
}



class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i=1;i<=n;i++) {
            if(isGood(i)) count++;
        }

        return count;
    }
};