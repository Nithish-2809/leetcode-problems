class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int breakPoint = -1;
        for(int i=n-1;i>=0;i--) {
            if((num[i]-'0')%2!=0) {
                breakPoint = i;
                break;
            }
        }

        if(breakPoint==-1) return "";

        return num.substr(0,breakPoint+1);
    }
};