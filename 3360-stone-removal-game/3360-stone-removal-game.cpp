class Solution {
public:
    bool canAliceWin(int n) {
        bool aliceTurn = true;
        int pick = 10;

        while(n>0) {
            if(aliceTurn) {
                if(n<pick) return false;
                n -= pick;
                pick--;
                aliceTurn = false;
            }
            else {
                if(n<pick) return true;
                n -= pick;
                pick--;
                aliceTurn = true;
            }
        }

    if(n==0 && aliceTurn) return false;

    return true;
    }
};