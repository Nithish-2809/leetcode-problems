class Solution {
public:
    string largestOddNumber(string num) {
        
       int n = num.length();
       int ind = -1;

       for(int i=n-1;i>=0;i--) {
        if(num[i]%2==1) {
            ind = i;
            break;
        }
       }

        if(ind == -1) return "";
        
        string ans = num.substr(0,ind+1);

        return ans;
    }
};