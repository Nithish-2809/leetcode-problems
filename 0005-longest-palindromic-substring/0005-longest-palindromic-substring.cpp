class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n==0) return "";

        string lps = "";
        int maxLen = 0;

        for(int i=0;i<n;i++) {
            
            int right = i;
            int left =  i;

            while(right<n && left>=0 && s[right]==s[left]) {
                if((right-left+1)>maxLen) {
                    maxLen = right-left+1;
                    lps = s.substr(left,right-left+1);
                }
                right++;
                left--;
            }


            right = i+1;
            left = i;

            while(right<n && left>=0 && s[right]==s[left]) {
                if((right-left+1)>maxLen) {
                    maxLen = right-left+1;
                    lps = s.substr(left,right-left+1);
                }
                right++;
                left--;
            }

        }

        return lps;
    }
};